﻿using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WebApi.Data;
using WebApi.Models.DB;
using WebApi.Models.DTO;

namespace WebApi.Controllers
{
    // 제대로된 프레임워크나
    // 제대로된 엔진을 사용하면
    // 블랙박스라는게 존재
    // 블랙박스
    //  => 우리가 실제로 코드를 볼 수 없지만,
    //  우리가 못보는곳에서 무언가를 하는 것

    //builder.Services.AddControllers();
    // => 컨트롤러를 쓰겠다. 
    // 라는것을 선언함과 동시에
    // 모든 컨트롤러는 종속성이 생성된다.

    // builder 안에 내가 원하는 서비스를 집어넣으면
    // 생성자에서 다 받을 수 있다
    // builder => 모든 서비스를 알아서 잘 딱 맞게 
    //   생성자에 원하는 내용을 넣어준다.

    // ILogger<객체> 는 가장 기본적인 ASP. NET 서버의 logger 형태다.

    [ApiController]
    [Route("[controller]")]
    public class UserController : ControllerBase
    {
        private static int _newUserId = 1;
        private static List<User> _users = new List<User>();
        // 사실 이 List가 DB에 있기 떄문에 이걸 DB에서 가져오고 갔다놓고 하는걸 할 수 있으면 된다.
        private readonly Context _context;

        //Get Method
        //id를 통해서 User정보 조회

        //Post Method
        //유저를 새롭게 추가

        //Put Method
        //Id와 Email을 넣으면
        //해당 Id의 Email이 변경되도록 수정

        //Delete Method
        //Id를 넣으면
        //해당 유저가 삭제되게 수정

        private readonly ILogger<UserController> _logger;
        public UserController(ILogger<UserController> logger, Context context)
        {
            _logger = logger;
            _context = context;
        }

        [HttpGet("TestGet")]
        public async Task<object> GetPchTblUsers() // async는 비동기
        {
            // 클라이언트 <-> 서버 <-> DB
            //
            // 클라이언트 => 서버에 요청보낼때, 로딩바를 보통 띄워둡니다.
            // 로그인할때.
            // indicator (삥글뻉글 돌아감)
            // 서버 <-> DB

            object rv;

            rv = await _context.PchTblUsers
                .Include(user => user.ChampionKeyNavigation)
                .Include(user => user.PchTblUserItems)
                .Select(user => new
                {
                    UserKey = user.Key,
                    ChampionName = user.ChampionKeyNavigation.Name,
                    UserLevel = user.Level,
                    ItemCount = user.PchTblUserItems.Count
                })
                .ToListAsync();

            // 이 방법으로도 된다. 선생님은 이걸 더 선호하고 대부분 이걸 많이 쓴다.
            var query = await (
                from user in _context.PchTblUsers
                where user.Key == 1
                select new
                {
                    UserKey = user.Key,
                    ChampionName = user.ChampionKeyNavigation.Name,
                    UserLevel = user.Level,
                    ItemCount = user.PchTblUserItems.Count
                })
                .ToListAsync();

            return query; // return rv; 해도 됨
        }

        [HttpGet("GetChampionInfoByUserKey")]
        public async Task<CommonResult<ResponseDtoGetChampionInfoByUserKey>> GetChampionInfoByUserKey([FromQuery] RequestDtoGetChampionInfoByUserKey requestDto)
        {
            CommonResult<ResponseDtoGetChampionInfoByUserKey> rv = new ();

            try
            {
                _context.BsyTblUsers.Include(user => user.ChampionKeyNavigation);

                var query = await (
                   from user in _context.BsyTblUsers
                   where user.Key == requestDto.UserKey
                   select new ResponseDtoGetChampionInfoByUserKey
                   {
                       UserKey = user.Key,
                       ChampionLevel = user.Level ?? 0,
                       ChampionName = user.ChampionKeyNavigation.Name
                   }).ToListAsync();

                /*
                 * SELECT `b`.`_key` AS `UserKey`, `b`.`_level` AS `ChampionLevel`, `b0`.`_name` AS `ChampionName`
                 * FROM `BSY_TblUser` AS `b`
                 * LEFT JOIN `BSY_TblChampion` AS `b0` ON `b`.`_championKey` = `b0`.`_key`
                 * WHERE `b`.`_key` = @__userKey_0
                 */

                if (query.Count < 1)
                {
                    throw new CommonException(EStatusCode.NotFoundEntity, "해당 키를 가진 유저가 없습니다.");
                }

                var selectUser = query.First();

                rv.StatusCode = EStatusCode.OK;
                rv.Message = "";
                rv.IsSuccess = true;
                rv.Data = selectUser;

            }
            catch (CommonException ex)
            {
                rv.StatusCode = (EStatusCode)ex.StatusCode;
                rv.Message = ex.ToString();
                rv.IsSuccess = false;
                rv.Data = (ResponseDtoGetChampionInfoByUserKey)ex.Data;
            }
            catch (Exception ex)
            {
                rv.StatusCode = EStatusCode.ServerException;
                rv.Message = ex.ToString();
                rv.IsSuccess = false;
                rv.Data = null;
            }
            return rv;
        }

        [HttpGet("GetItemListByUserKey")]
        public async Task<ResponseDtoGetItemListByUserKey> GetItemListByUserKey([FromQuery] RequestDtoGetItemListByUserKey requestDto)
        {
            ResponseDtoGetItemListByUserKey rv = new();

            // [itemKey, itemName]의 List형태로 리턴
            rv.List = await (
              from userItem in _context.BsyTblUserItems
              where userItem.UserKey == requestDto.UserKey
              select new ResponseDtoGetItemListByUserKeyElement
              {
                  ItemKey = userItem.Key,
                  ItemName = userItem.ItemKeyNavigation.Name
              }).ToListAsync();

            /*
             * SELECT `b`.`_itemKey` AS `ItemKey`, `b0`.`_name` AS `ItemName`
             * FROM `BSY_TblUserItem` AS `b`
             * LEFT JOIN `BSY_TblItem` AS `b0` ON `b`.`_itemKey` = `b0`.`_key`
             * WHERE `b`.`_userKey` = @__userKey_0
             */

            //1. List<Dto> 형태로 리턴한다.
            //  서버, 클라이언트 둘다하는 사람이 많이 적습니다.
            //  서버입장에서는 List<Dto>로 리턴하는게 상당히 많이 편합니다.
            //  클라이언트 입장에서는 저렇게 Return해줬을때 코드로 파싱하는 경우에서 많이 까다로울떄가 많아요.

            //2. Dto에 리스트를 포함한다.


            return rv;
        }

        [HttpGet("GetSkillListByUserKey")]
        public async Task<ResponseDtoGetSkillListByUserKey> GetSkillListByUserKey([FromQuery] RequestDtoGetSkillListByUserKey requestDto)
        {
            ResponseDtoGetSkillListByUserKey rv = new();

            // [skillKey, skillName]의 List형태로 리턴
            rv.List = await (
              from userSkill in _context.BsyTblUserSkills
              where userSkill.UserKey == requestDto.UserKey
              select new ResponseDtoGetSkillListByUserKeyElement
              {
                  SkillKey = userSkill.Key,
                  SkillName = userSkill.SkillKeyNavigation.Name
              }).ToListAsync();


            /*
             * SELECT `b`.`_key` AS `SkillKey`, `b0`.`_name` AS `SkillName`
             * FROM `BSY_TblUserSkill` AS `b`
             * LEFT JOIN `BSY_TblSkill` AS `b0` ON `b`.`_skillKey` = `b0`.`_key`
             * WHERE `b`.`_userKey` = @__requestDto_UserKey_0
             */

            return rv;
        }

        [HttpPost("InsertUserSkill")]
        public async Task<CommonResult<ResponseDtoInsertUserSkill>> InsertUserSkill([FromBody] RequestDtoInsertUserSkill requestDto)
        {
            CommonResult<ResponseDtoInsertUserSkill> rv = new();

            // GET으로 해도 할 수는 있는데 GET은 조회하는 것이기 때문에
            // 의미가 안맞다

            // 함수명을 GetSkill이라고 해놓고
            // 본문내용은 InsertSkill 이라고 하는 행동이랑 크게 다를게 없다.

            // 그러니 Post로 써주겠다.

            try
            {
                _context.PchTblUserSkills.Add(new PchTblUserSkill()
                {
                    SkillKey = requestDto.SkillKey,
                    UserKey = requestDto.UserKey
                });

                var IsSuccess = await _context.SaveChangesAsync();

                if(IsSuccess ==0)
                {
                    throw new CommonException(EStatusCode.ChangedRowsIsZero, $"SkillKey : {requestDto.SkillKey},  UserKey: {requestDto.UserKey}");
                }

                rv.IsSuccess = true;
                rv.StatusCode = EStatusCode.OK;
                rv.Data = null;
            }
            catch(CommonException ex)
            {
                rv.IsSuccess = false;
                rv.StatusCode =  (EStatusCode)ex.StatusCode;
                rv.Message = ex.Message;
                rv.Data = null;
            }
            catch (Exception ex)
            {
                rv.IsSuccess = false;
                rv.StatusCode = EStatusCode.ServerException;
                rv.Message = ex.Message;
                rv.Data = null;
            }



            return rv;
        }


        [HttpGet()]
        public User Get([FromQuery]int id)
        {
            //User user = new User();
            //foreach (var item in _users)
            //{
            //    if(item.Id == id)
            //    {
            //        return user;
            //    }
            //}
            //return null;

            // linq 방식으로 하면

            // users 안에 있는 리스트를 
            // u라는 이름으로 순회하면서
            // u.Id == id이면
            // 배열이 나오는데
            // 그 중에서 첫번째 요소를 가져오겠다.
            // 첫번째 요소가 없으면 Default 값으로 가져오겠다.

            var rv = _users.Where(u => u.Id == id).FirstOrDefault();

            if (rv == null) 
            {
                throw new Exception("Bad Request");
            }

            return rv;
        }

        // 이런건 bool함수로 만들어서 그 결과를 true, false로 해주는게 좋다
        // 난 처음에 모르고 void로 했었다.
        [HttpPost()]
        public bool Create([FromQuery] string name, string email, string passward)
        {
            User newUser = new User()
            {
                Id = _newUserId,
                Name = name,
                Email = email,
                Password = passward
            };

            //user.Id = _newUserId;
            //user.Name = name;
            //user.Email = email;
            //user.Password = passward;
            // C#에선 이렇게 하는것 보단 위처럼 선언하면서 하는게 좋다.

            _users.Add(newUser);

            _newUserId++;

            return true;
        }

        [HttpPut()]
        public bool Update([FromQuery] int id, string email)
        {
            //User user = new User();
            //foreach (var item in _users)
            //{
            //    if (item.Id == id)
            //    {
            //        user.Email = email;
            //    }
            //}

            var user = _users.Where(u => u.Id == id).FirstOrDefault();

            if (user == null)
            {
                return false;
            }

            user.Email = email;

            // User => Class (Heap Memory)
            // List<User> => Class (Heap Memory)
            // List<User> 들고있는 데이터 값은 주소값이다.
            // user 를 찾은 시점에서 주소값에서 변경하는것

            // 근데 만약 User가 Struct였으면
            // 그러면 몇번째인지 찾아내서
            // _users[0] = user 이렇게 대입을 확실히 해줘야 한다.

            return true;
        }

        [HttpDelete()]
        public bool Delete([FromQuery] int id)
        {
            //foreach (var item in _users)
            //{
            //    if (item.Id == id)
            //    {
            //        _users.Remove(item);
            //    }
            //}

            User deleteUser = _users.Where(u => u.Id == id).FirstOrDefault();

            if (deleteUser == null)
            {
                return false;
            }

            _users.Remove(deleteUser);
            return true;
        }

        //HTTP 통신 특징
        // Method를 같이 보내게 되어있습니다.
        // URL + Method를 통해서 어떤 Controller의 어떤 함수로 접근할건지
        // Method 중에 하나가 GET
        // 많이 쓰는 Method는
        // GET, POST, PUT, DELETE 

        // 함수명을 
        // GetItem
        // 이라고 지어놓고
        // 사실은 이함수에서 해주는역할이
        // 게임을 시작하는 함수 이런 식으로 어긋날 수 있다.

        // 좋은코드는 함수명만봐도 대충 뭐하는앤지 알아야한다.
        // GetUserData
        // UpdateUserData
        // 특정 데이터를 진짜진짜 극도로 아껴야하는 프로젝트에서는 
        // 저글자수마저 데이터가 아깝다.

        // 기본적으로 Method에 의미를 담자

        // Method GET 에 User Controller 함수를 호출하면
        //  User를 Get 해주는

        // Method POST 에 User Controller 함수를 호출하면
        //  User를 Create 해주는

        // Method PUT 에 User Controller 함수를 호출하면
        //  User를 Update 해주는

        // Method DELETE 에 User Controller 함수를 호출하면
        //  User를 Delete 해주는

        // API로 만들자 (REST Api 규약)

        //------------------------------------
        //      축약버전
        //------------------------------------

        // Method GET 에 User Controller 함수를 호출하면
        //  User를 Get 해주는

        // Method POST 에 User Controller 함수를 호출하면 Create, Update, Delete 모두 유저의 정보가 변하는 것
        //  User의 정보가 변하게 해주는
    }
}

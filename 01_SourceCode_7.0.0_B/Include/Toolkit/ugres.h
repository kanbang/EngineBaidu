#ifndef UGRES_H
#define UGRES_H




// 与磁盘相关的读写错误
#define	UGS_OUTPUT_BUFFER_HAS_NO_ENOUGH_ROOM    _U("EAa001")	/*! 输出缓存没有足够的空间*/
#define	UGS_DISK_HAS_NO_ENOUGH_ROOM             _U("EAa002")	/*! 磁盘空间不足*/
#define	UGS_DISK_SINGLE_FILE_SIZE_LIMIT_2G      _U("EAa003")	/*! 文件大小不能超过2G*/
#define	UGS_DISK_SPACE_NOT_ENOUGH_OR_SINGLE_FILE_SIZE_LIMIT _U("EAa004")	/*! 磁盘空间不足,或者是数据文件已经超过了磁盘的文件限制*/

// 描述与文件或者数据库权限相关的错误信息
#define	UGS_PASSWORD_ERROR                      _U("EAb001")	/*! 密码错误*/
#define	UGS_ENG_READONLY                        _U("EAb002")	/*! 只读，不能进行修改操作。*/
#define	UGS_CANNOT_MODIFY_PASSWORD              _U("EAb003")	/*! 不允许修改密码*/
#define	UGS_SYSTEMUSER_FORBID_CREATING_DATASOURCE _U("EAb004")	/*! 系统用户不允许创建数据源*/
#define	UGS_DATASOURCE_READONLY                 _U("EAb005")	/*! 数据源只读*/
#define	UGS_DATA_ATTRIBUTE_READONLY             _U("EAb006")	/*! 数据属性为只读*/
#define	UGS_DATASET_READONLY                    _U("EAb007")	/*! 数据集为只读状态*/
#define	UGS_MODIFY_PASSWORD_FAILD               _U("EAb008")	/*! 修改密码失败*/
#define UGS_DATASOURCE_OCCUPIED_OR_BAD          _U("EAb009")  /*! 数据源被独占或文件损坏*/
#define UGS_SDBPLUS_DATASOURCE_VERSION_ERROR  _U("EAb010")  /*! SDBPlus版本不兼容，不支持低版本的SDB数据*/


// 描述与文件或数据内容相关的错误信息
#define	UGS_WORKSPACE_IS_NULL                   _U("EAc001")	/*! 工作空间为空*/
#define	UGS_TEMPLATE_FILE_IS_EMPTY              _U("EAc002")	/*! 模板文件内容为空*/
#define	UGS_FILE_GOT_FROM_WEB_IS_EMPTY          _U("EAc003")	/*! 从网络上得到的文件为空*/
#define	UGS_DATA_ERROR                          _U("EAc004")	/*! 数据错误*/
#define	UGS_SAVE_BYTE_LENGTH_LESSTHAN_ZERO      _U("EAc005")	/*! ICON文件的字节数不能小于0*/
#define	UGS_NOT_FIND_XML_LABEL                  _U("EAc006")	/*! XML文件找不到标签：%s*/

// 描述文件或数据已经存在、或不存在而导致的读写错误，包括工作空间、数据源、数据集、记录集等
#define	UGS_WORKSPACE_NOT_EXIST                 _U("EAd001")	/*! 工作空间不存在*/
#define	UGS_TEMPLATE_FILE_NOT_EXIST             _U("EAd002")	/*! 模板文件不存在*/
#define	UGS_CURRENT_DS_NOT_EXIST                _U("EAd003")	/*! 当前数据源不存在*/
#define	UGS_FILE_NOT_EXIST                      _U("EAd004")	/*! 文件不存在*/
#define	UGS_RS_NOT_EXIST                        _U("EAd005")	/*! 记录集不存在*/
#define	UGS_RECORDSET_AT_THIS_INDEX_NOT_EXIST   _U("EAd006")	/*! 指定索引的记录集不存在*/
#define	UGS_THE_METADATA_NOT_EXIST              _U("EAd007")	/*! 当前数据集的元数据不存在*/
#define	UGS_MAP_NOT_EXIST                       _U("EAd008")	/*! 名字为%s的地图不存在*/
#define	UGS_LAYOUT_NOT_EXIST                    _U("EAd009")	/*! 名字为%s的布局不存在*/
#define	UGS_THE_REGEDIT_IS_NONENTITY            _U("EAd010")	/*! 注册文件不存在*/
#define	UGS_FILE_S_IS_EXIST                     _U("EAd011")	/*!  %s 已存在*/
#define	UGS_FILE_IS_EXIST                       _U("EAd012")	/*! 文件已存在*/
#define	UGS_CANNOT_DELETE_FILE                  _U("EAd013")	/*! 无法删除文件*/
#define	UGS_DATASET_NOT_EXIST                   _U("EAd014")	/*! 数据集不存在*/
#define	UGS_DATASOURCE_DATASET_ACTION_RESULT_ERROR _U("EAd015")	/*! \n 数据源: %s; \n 数据集: %s;\n 动作: %s;\n 结果: %d;\n 错误描述: %s\n*/
#define UGS_FILE_NOT_OPEN                       _U("EAd016")	/*! 文件未打开*/

// 描述文件或数据格式非法而导致的读写错误
#define	UGS_NOT_SUPPORT_FILE_TYPE               _U("EAe001")	/*! 不支持的文件类型*/
#define	UGS_READ_INFO_FAILED                    _U("EAe002")	/*! 读取文件信息失败*/
#define	UGS_INVALID_OGC_FILE                    _U("EAe003")	/*! OGC网络数据文件错误*/
#define	UGS_INVALID_FILE                        _U("EAe004")	/*! 文件不合法*/
#define	UGS_INVALID_FORMAT                      _U("EAe005")	/*! 文件不是 %s 格式*/
#define UGS_INVALID_OGC_VERSION                 _U("EAe006")    /*! OGCWCS服务支持到版本%s，当前版本不支持!*/

// 描述因为文件名称或路径不合法导致的读写错误
#define	UGS_NAME_IS_NULL                        _U("EAf001")	/*! 名字为空*/
#define	UGS_DATASET_NAME_INVALID                _U("EAf002")	/*! 数据集名称非法*/
#define	UGS_SAME_DATASET_NAME                   _U("EAf003")	/*! 数据集名称相同*/
#define	UGS_IMPORT_FILE_NAME_IS_NULL            _U("EAf004")	/*! 要导入的数据文件名为空*/
#define	UGS_THE_FILE_NAME_IS_NONENTITY          _U("EAf005")	/*! 此文件名不存在*/
#define	UGS_ORIGINAL_FILE_NAME_IS_NULL          _U("EAf006")	/*! 源文件名为空*/
#define	UGS_NAME_LENGTH_OVERRUN                 _U("EAf007")	/*! 名称长度不能超过30个字符*/
#define	UGS_NAME_AGAIN_SYSTEMNAME               _U("EAf008")	/*! 名称不能与系统保留字段相同*/
#define	UGS_NAME_PREFIX_ERROR                   _U("EAf009")	/*! 名称不能以数字或下划线开头*/
#define	UGS_HOMONYMY_DATASET_EXIST              _U("EAf010")	/*! 同名数据集已经存在*/
#define	UGS_WORKSPACE_NAME_IS_EMPTY             _U("EAf011")	/*! 工作空间名称为空*/
#define	UGS_TEMPLATE_NAME_IS_EMPTY              _U("EAf012")	/*! 模板名为空*/
#define	UGS_SERVER_IS_NULL                      _U("EAf013")	/*! 路径为空*/
#define	UGS_INVALID_DS_PATH                     _U("EAf014")	/*! 数据源路径非法*/
#define	UGS_NAME_IS_NONENTITY                   _U("EAf015")	/*! 名称已存在*/
#define	UGS_VERSION_NAME_IS_EMPTY               _U("EAf016")	/*! 版本名为空*/
#define	UGS_DIR_FILENAME_IS_INVALID             _U("EAf017")	/*! 带路径文件名非法*/
#define	UGS_VERSION_NUMBER_ILLEGAL              _U("EAf018")	/*! 参数非法：版本号小于1*/
#define	UGS_ACTIONID_IS_ZERO                    _U("EAf019")	/*! 参数非法：操作号为0*/
#define	UGS_FORMAT_IS_NULL                      _U("EAf020")	/*! 格式为空*/
#define	UGS_EDITION_INVALID                     _U("EAf021")	/*! 版本号不对*/

// 文件相关操作错误，如创建、删除、打开、保存等
#define	UGS_FROMXML_FAILED                      _U("EAg001")	/*! 解析XML文件失败*/
#define	UGS_XML_DATA_ERROR                      _U("EAg002")	/*! XML文件加载失败*/
#define	UGS_FAILED_TO_READ_XML_INFO_            _U("EAg003")	/*! 从文件中读取XML信息失败*/
#define	UGS_FAILED_TO_SAVE_SXW_FILE             _U("EAg004")	/*! 存储工作空间为xml文件失败*/
#define	UGS_FAILED_TO_SAVE_SUW                  _U("EAg005")	/*! 保存SUW工作空间失败*/
#define	UGS_FAILED_TO_SAVE_SXW                  _U("EAg006")	/*! 保存SXW工作空间失败*/
#define	UGS_FAILED_TO_SAVE_WORKSPACE            _U("EAg007")	/*! 保存工作空间失败*/
#define	UGS_FAILED_TO_SAVEAS_SUW                _U("EAg008")	/*! 另存SUW工作空间失败*/
#define	UGS_FAILED_TO_SAVEAS_SXW                _U("EAg009")	/*! 另存SXW工作空间失败*/
#define	UGS_FAILED_TO_SAVEAS_WORKSPACE          _U("EAg010")	/*! 另存工作空间失败*/
#define	UGS_FAILED_TO_OPEN_SUW                  _U("EAg011")	/*! 打开SUW工作空间失败*/
#define	UGS_FAILED_TO_OPEN_SXW                  _U("EAg012")	/*! 打开SXW工作空间失败*/
#define	UGS_FAILED_TO_OPEN_WORKSPACE            _U("EAg013")	/*! 打开工作空间失败*/
#define	UGS_ODBC_LOADWORKSPACE_FAILED           _U("EAg014")	/*! 加载工作空间失败*/
#define	UGS_WORKSPACE_SAVEAS_BINARY_FILE_TO_DB_FAILED _U("EAg015")	/*! 保存工作空间二进制文件到数据库失败*/
#define	UGS_ODBC_GETWORKSPACEINFO_FAILED        _U("EAg016")	/*! 获取工作空间信息失败*/
#define	UGS_ODBC_DELETEWORKSPACEINFO_FAILED     _U("EAg017")	/*! 删除工作空间信息失败*/
#define	UGS_FAILED_TO_OPEN_UGPJFILE             _U("EAg018")	/*! 打开坐标参考文件失败*/
#define	UGS_FAILED_TO_OPEN_DICTIONARY           _U("EAg019")	/*! 打开词典文件失败*/
#define	UGS_FILE_OPEN_FAILED                    _U("EAg020")	/*! 文件（%s）打开失败*/
#define	UGS_FILE_CREATE_FAILED                  _U("EAg021")	/*! 文件（%s）创建失败*/
#define	UGS_FILE_WRITE_FAILED                   _U("EAg022")	/*! 文件（%s）写入失败*/
#define	UGS_FILE_READ_FAILED                    _U("EAg023")	/*! 文件（%s）读取失败*/
#define	UGS_MEMORY_FILE_S_CREATE_FAILED         _U("EAg024")	/*! 缓存文件 %s 创建失败*/
#define	UGS_FAILED_TO_GENERATE_FILE             _U("EAg025")	/*! 生成数据文件: %s 失败*/
#define	UGS_SQLPLUS_ADDTEMPLATEFILE_FAILED      _U("EAg026")	/*! 添加模板文件失败*/
#define	UGS_DEAL_WITH_DATAFILE_S_FAILED         _U("EAg027")	/*! 处理数据文件:%s 失败*/
#define	UGS_FAILED_TO_UNZIP                     _U("EAg028")	/*! 解压缩文件失败*/
#define	UGS_UGLAYOUTSTORAGES_FAILED_TO_FROMXML  _U("EAg029")	/*! 解析包含布局文件路径信息的XML文件失败*/
#define	UGS_FAILED_TO_READ_XML_INFO_FROM_FILE_S _U("EAg030")	/*! 从文件%s中读取XML信息失败*/
#define	UGS_UGWORKSPACE_BOXINGSXW_FAILED_OPEN_FILE_S_FAILED _U("EAg031")	/*! 打开文件%s失败，将SXW文件包装成字节失败*/
#define	UGS_FAILED_TO_OPEN_FILE                 _U("EAg032")	/*! 打开文件: %s 失败*/
#define	UGS_FAILED_TO_OPEN_TEXT                 _U("EAg033")	/*! 打开文本文件失败*/
#define	UGS_NOT_GET_FILE_FROM_WEB_CORRECTLY     _U("EAg034")	/*! 从网络上得到文件错误*/
#define	UGS_FAILED_TO_CREATE_FILE_TYPE_PARSER   _U("EAg035")	/*! 创建文件格式解析器失败*/
#define	UGS_CREATE_FILE_FORMAT_PARSER_SUCCESS   _U("EAg036")	/*! 创建文件格式解析器成功*/
#define	UGS_FAILED_TO_CREATE_DEMAND_POINTS_FILE _U("EAg037")	/*! 创建需求点文件失败*/
#define	UGS_FILE_IS_OPEN                        _U("EAg039")	/*! 文件已打开*/
#define	UGS_FAILED_TO_READ_XML                  _U("EGg040")	/*! %s读取XML信息失败*/
#define	UGS_FAILED_TO_SAVEAS_XML                _U("EGg041")	/*! %s保存为XML文件失败*/
#define	UGS_DATASET_IS_OPEN                     _U("EAg042")	/*! 数据集已打开*/
#define	UGS_FAILED_TO_READ_CACHEFILE_WITH_TILE_D _U("EAg043")	/*! 读取图幅%d的缓存文件失败*/
#define	UGS_FAILED_TO_LOAD_DICTIONARY           _U("EAg044")	/*! 加载地址词语字符串失败*/
#define	UGS_CREATE_FILE                         _U("EAg045")	/*! 创建成功*/
#define	UGS_CREATE_FILE_FAILED                  _U("EAg046")	/*! 创建失败*/
#define	UGS_WRONG_PASSWORD_OR_FILE_CORRUPTED    _U("EAg047")	/*! 密码错误或文件损坏*/
#define	UGS_WRONG_COORDINATE_SYSTEM_TO_CREATE_CACHE _U("EAg048")	/*! 只有使用地理坐标系的地图能够生成三维地图缓存*/
#define	UGS_FAILED_SAVEAS_XML_FILE              _U("EAg049")	/*! 保存为XML文件失败*/
#define	UGS_FAILED_OPEN_MDB_TABLE               _U("EAg050")	/*! MDB文件(%s)表打开失败*/
#define	UGS_FAILED_OPEN_MDB_DATA                _U("EAg051")	/*! MDB文件(%s)表记录打开失败*/



// 描述内存不足相关的错误信息
#define	UGS_MEMORY_ALLOTE_SHORTAGE              _U("EBa001")	/*! 内存分配不足*/
#define	UGS_FAILED_TO_APPLY_MEMORY              _U("EBa002")	/*! 申请内存失败*/
#define	UGS_FAILED_TO_ALLOT_MEMORY              _U("EBa003")	/*! 内存分配失败*/
#define	UGS_MEMORY_SIZE_ILLEGAL                 _U("EBa004")	/*! 内存大小非法*/
#define	UGS_MEMORY_APPLY_UNEXPECTED             _U("EBa005")	/*! 内存分配异常*/
#define UGS_FAILED_APPLY_CONTINUOUS_MEMORY      _U("EBa006")	/*! 申请连续%dM内存失败*/



// 字段类型不合法
#define	UGS_THEMECUSTOM_FIELD_TYPE_INVALID      _U("ECa001")	/*! 自定义专题图字段类型不合法*/
#define	UGS_THEMESYMBOL_FIELD_INVLAID           _U("ECa002")	/*! 符号专题图字段类型不合法*/
#define	UGS_THEMEDOTDENSITY_FIELD_INVALID       _U("ECa003")	/*! 点密度专题图字段类型不合法*/
#define	UGS_THEMEUNIQUE_FIELD_INVALID           _U("ECa004")	/*! 单值专题图字段类型不合法*/
#define	UGS_THEMELABEL_FIELD_INVALID            _U("ECa005")	/*! 标签专题图字段类型不合法*/
#define	UGS_THEMEGRADUATE_FIELD_INVALID         _U("ECa006")	/*! 等级符号专题图字段类型不合法*/
#define	UGS_THEMEGRAPH_FIELD_INVALID            _U("ECa007")	/*! 统计专题图字段类型不合法*/
#define	UGS_THEMERANGE_FIELD_INVALID            _U("ECa008")	/*! 范围专题图字段类型不合法*/
#define	UGS_ERROR_COV_FIELDTYPE                 _U("ECa009")	/*! 非法的字段类型*/
#define	UGS_DATA_TYPE_NOT_MATCH                 _U("ECa010")	/*! 字段值的类型与需要更新的字段类型不匹配*/
#define	UGS_DIRECTION_TYPE_IS_NOT_LONG          _U("ECa011")	/*! 流向字段类型不是长整型类型*/
#define	UGS_SELECTED_COSTFIELD_INVALID          _U("ECa012")	/*! 用户选择的耗费字段非法*/
#define	UGS_ERROR_UGVARIANT_TYPE                _U("ECa013")	/*! 不支持此种数据类型*/
#define	UGS_BIN_FIELD_LENGTH_INVALID            _U("ECa014")	/*! 二进制字段长度非法*/

// 字段名称不合法
#define	UGS_INVALID_FIELD_NAME_LENGTH           _U("ECb001")	/*! 字段(%s)长度不能超过30个字节*/
#define	UGS_CANNOT_CREATE_FIELD_FOR_FILED_NAME_LENGTH_OVERRUN _U("ECb002")	/*! 字段名称长度不能超过30个字节*/
#define	UGS_FIELD_NAME_ALREADY_EXIST            _U("ECb003")	/*! 字段名已存在*/
#define	UGS_FIELD_NAME_NOT_EXIST                _U("ECb004")	/*! 字段名称不存在*/
#define	UGS_FIELD_IS_EMPTY                      _U("ECb005")	/*! 字段为空*/
#define	UGS_FIELD_NAME_INVALID                  _U("ECb006")	/*! 字段名非法*/
#define	UGS_FILED_NAME_AND_FORMAT_CANNOT_BE_EMPTY _U("ECb007")	/*! 字段别名及格式不能为空*/
#define	UGS_UUID_FIELD_ALREADY_EXIST            _U("ECb008")	/*! UUID字段已存在*/
#define UGC_ALTER_APPEND_FIELD_NAME				_U("ECb009")	/*! 指定的字段名%已存在，已修改为%*/

// 字段的值不合法，包括字段表达式
#define	UGS_THEMEGRADUATE_FIELD_EXPRESSION_IS_NULL _U("ECc001")	/*! 等级符号专题图字段表达式为空*/
#define	UGS_THEME_INVALID_EXPRESSION            _U("ECc002")	/*! 专题图字段表达式非法*/
#define	UGS_COSTFIELD_IS_NULL                   _U("ECc003")	/*! 花费字段为空*/
#define	UGS_NETWORK_NODEDEMAND_IS_NULL          _U("ECc004")	/*! 网络节点需求字段为空*/
#define	UGS_NETWORK_ARCDEMAND_IS_NULL           _U("ECc005")	/*! 网络弧段需求字段为空*/
#define	UGS_TRN_FIELD_ERROR                     _U("ECc006")	/*! 转向表字段为空*/
#define	UGS_TFWEIGHT_AND_FTWEIGHT_ARE_NULL      _U("ECc007")	/*! 正向和反向字段为空*/
#define	UGS_GEOMETRY_SETTED_ORIGINAL_SMID_ISNOT_NEGATIVE_ONE _U("ECc008")	/*! 设置的几何对象初始化的SmID不为-1*/
#define	UGS_DIRECTION_IS_NULL                   _U("ECc009")	/*! 流向字段为空*/
#define	UGS_TWO_PARAM_DIFFERENCE                _U("ECc010")	/*! 参数错误：两个数据集的%s不相等*/
#define	UGS_TURN_COST_IS_EMPTY                  _U("ECc011")	/*! 转向阻值字段为空*/
#define	UGS_NETWORK_ADJMATRIX_IS_NULL           _U("ECc012")	/*! 邻接矩阵为空*/
#define	THE_FILED_VALUE_IS_ZERO                 _U("ECc013")	/*! 字段值为0*/
#define	UGS_ILLEGAL_ID                          _U("ECc014")	/*! 传入 ID =%s 非法*/
#define UGS_THE_FILED_VALUE_CANNOT_IS_EMPTY     _U("ECc015")    /*! 字段%s的值不能为空*/
#define UGS_THE_SAME_ID							_U("ECc016")	/*! 第 %d 个站点和第 %d 相同，不合法*/

// 字段的相关操作错误
#define	UGS_FAILED_TO_GET_FIELD_INFO            _U("ECd001")	/*! 获取字段信息失败*/
#define	UGS_FAILED_TO_GET_FIELDVALUE            _U("ECd002")	/*! 获取字段值失败*/
#define	UGS_FAILED_GET_GRADE_FIELD              _U("ECd003")	/*! 获取等级字段失败*/
#define	UGS_FAILED_TO_GET_NETWORK_FIELD         _U("ECd004")	/*! 获取网络数据集字段失败*/
#define	UGS_FAILED_TO_GET_COST_FIELD            _U("ECd005")	/*! 获取花费字段失败*/
#define	UGS_ODBC_GETFILEDNAME_BY_SIGN_FAILED    _U("ECd006")	/*! 通过字段类别获取字段名称失败*/
#define	UGS_ODBC_SETIFILEDINFO_FAILED           _U("ECd007")	/*! 设置字段信息失败*/
#define	UGS_ODBC_STATISTIC_FAILED               _U("ECd008")	/*! 统计字段值失败*/
#define	UGS_THEMELABEL_FINDTEXTSTYLE_FAILED_TO_FIND_FIELDVALUE _U("ECd009")	/*! 标签专题图查找记录集对应字段值失败*/
#define	UGS_FAILED_TO_ADD_FIELDVALUE            _U("ECd010")	/*! 添加段值失败*/
#define	UGS_FAILED_TO_INSERT_FIELDVALUE         _U("ECd011")	/*! 插入段值失败*/
#define	UGS_CANNOT_DELETE_SYSTEM_FIELD          _U("ECd012")	/*! 不能删除系统字段*/
#define	UGS_FAILED_TO_CREATE_FIELDS             _U("ECd013")	/*! 创建字段失败*/
#define	UGS_CREATE_FIELD_S_FAILED               _U("ECd014")	/*! 创建字段[%s]失败*/
#define	UGS_ODBC_DELETEFILED_FAILED             _U("ECd015")	/*! 删除字段失败*/
#define	UGS_ODBC_DELETEFILED_FAILED_LD          _U("ECd016")	/*! 删除字段[%ld]失败*/
#define	UGS_ODBC_COPYFIELD_FAILED               _U("ECd017")	/*! 复制字段失败*/
#define	UGS_ODBC_COPYFIELD_FAILED_S             _U("ECd018")	/*! 复制字段[%s]失败*/
#define	UGS_ODBC_CREATEFILED_FAILED             _U("ECd019")	/*! 添加字段失败*/
#define	UGS_ODBC_CREATEFILED_FAILED_S           _U("ECd020")	/*! 添加字段[%s]失败*/
#define	UGS_ODBC_SETFILEDNAME_BY_SIGN_FAILED    _U("ECd021")	/*! 设置字段类别失败*/
#define	UGS_FILED_NOT_EXIST                     _U("ECd022")	/*! 字段：%s不存在*/
#define	UGS_FILED_AT_THE_INDEX_NOT_EXIST        _U("ECd023")	/*! 索引为%d的字段不存在*/
#define	UGS_NOT_FIND_FILED                      _U("ECd024")	/*! 未找到字段：%s*/
#define	UGS_QUERY_FIELD_INFO_FAILED             _U("ECd025")	/*! 查询字段信息失败*/
#define	UGS_ODBC_CALCULATE_UNIQUEVALUES_FAILED  _U("ECd026")	/*! 计算字段单值失败*/
#define	UGS_NOT_SET_COST                        _U("ECd027")	/*! 没有设置花费字段*/
#define	UGS_ODBC_DELETEFILED_FAILED_LD_S        _U("ECd028")	/*! 删除字段[%ld:%s]失败*/
#define	UGS_FAILED_TO_INIT_FIELD_INFO           _U("ECd029")	/*! 初始化字段信息失败*/
#define	UGS_FAILED_TO_SET_DATASET_FIELD_VALUE_FLOAT _U("ECd030")	/*! 无法为数据集%s设置无值%.16f*/



// 与索引类型相关的错误信息
#define	UGS_THIS_TYPE_DATASET_NOT_SUPPORT_TILE_INDEX _U("EDa001")	/*! 该类型数据集不支持图幅索引*/
#define	UGS_THE_DATASET_NOT_SUPPORT_INDEX       _U("EDa002")	/*! 当前数据集不支持索引*/
#define	UGS_THE_DATASET_NEED_NOT_BUILDINDEX     _U("EDa003")	/*! 当前数据集不需要创建索引*/
#define	UGS_POINT_CANNOT_BUILDINDEX             _U("EDa004")	/*! 点数据集不能创建索引*/
#define	UGS_INDEXTYPE_INVALID                   _U("EDa005")	/*! 索引的类型不符*/
#define	UGS_INDEX_ISNOT_IDXRTREE                _U("EDa006")	/*! 索引类型不是R树索引*/
#define	UGS_INDEX_TYPE_ISNOT_IDXDYNAMIC         _U("EDa007")	/*! 索引类型不是动态索引*/
#define	UGS_INDEX_ISNOT_IDXQTREE                _U("EDa008")	/*! 索引类型不是四叉树索引*/
#define	UGS_INDEX_TYPE_IS_NOT_IDXTILE           _U("EDa009")	/*! 索引类型不是图幅索引*/
#define	UGS_THIS_DATASET_CANNOT_CREATE_DYNAMIC_INDEX _U("EDa010")	/*! 不支持该类型的数据集创建动态索引*/
#define	UGS_NOT_SUPPORT_THE_INDEX               _U("EDa011")	/*! 不支持的索引类型*/
#define	UGS_INVALID_DATASET_INDEX               _U("EDa012")	/*! 数据集的索引非法*/
#define	UGS_TILE_ID_ARRAY_IS_EMPTY              _U("EDa013")	/*! 图库索引ID数组为空*/

// 索引值错误
#define	UGS_INDEX_OF_FIELD_OUTOF_BOUNDS         _U("EDb001")	/*! 索引值非法：字段索引值为0或者大于字段总数*/
#define	UGS_INVALID_INDEX                       _U("EDb002")	/*! 索引值非法：[%s]的索引小于0，或者索引大于最大记录数*/
#define	UGS_INDEX_LARGER_THAN_THE_MAX_COUNT     _U("EDb003")	/*! 索引值非法：索引值小于等于0或者大于图层总数*/
#define	UGS_INVALID_INDEX_LOCATION              _U("EDb004")	/*! 索引位置非法*/
#define	UGS_ODBC_LIBTILE_BOUNDS_DONOT_FIT       _U("EDb005")	/*! 图幅范围不是矩形*/
#define	UGS_ODBC_LIBTILE_COUNT_OVERLIMIT        _U("EDb006")	/*! 图幅索引数超过最大值10000*/
#define	UGS_NODE_INDEX_NEGATIVE                 _U("EDb007")	/*! 索引值错误：节点索引不能小于0*/
#define	UGS_INVALID_TRACEPOINT_INDEX            _U("EDb008")	/*! 追踪点索引非法*/
#define	UGS_INDEX_OVERRUN                       _U("EDb009")	/*! 索引值非法：索引值超出范围*/
#define	UGS_INVALID_SUBLAYER_INDEX              _U("EDb010")	/*! 索引值非法：填充符号子层的索引不合法*/

// 索引表、索引包错误
#define	UGS_FAILED_TO_CREATE_INDEX_TABLE        _U("EDc001")	/*! 创建索引表失败*/
#define	UGS_INDEX_TABLE_EXIST                   _U("EDc002")	/*! 该索引表已经存在*/
#define	UGS_TILE_INDEX_TABLE_NOT_EXIST          _U("EDc003")	/*! 图幅索引表不存在*/
#define	UGS_IMPORT_INDEX_PACKAGE_IS_NULL        _U("EDc004")	/*! 传入的索引包为空*/
#define	UGS_GET_INDEX_PACKAGE_OBJECT_ID_FAILED  _U("EDc005")	/*! 获取索引包内对象ID失败*/
#define	UGS_GET_INDEX_PACKAGE_DATA_FAILED       _U("EDc006")	/*! 获取索引包内数据失败*/
#define	UGS_GET_INDEX_PACKAGE_MAX_FAILED        _U("EDc007")	/*! 获取索引包最大值失败*/
#define	UGS_GET_INDEX_PACKAGE_BOUNDS_FAILED     _U("EDc008")	/*! 获取索引包的范围失败*/
#define	UGS_GEOMETRY_ILLEGAL_IN_TILE_DATASET    _U("EDc009")	/*! 图幅索引数据集的图幅几何对象错误*/

// 索引状态，包括索引是否存在，是否脏等
#define	UGS_FILED_INDEX_NOT_EXIST               _U("EDd001")	/*! 字段索引不存在*/
#define	UGS_NOT_FIND_INDEX_OPPOSITE_THE_FILED_NAME _U("EDd002")	/*! 与字段名对应的索引不存在*/
#define	UGS_NOT_FIND_THE_OPPOSITE_ID_INDEX      _U("EDd003")	/*! 与ID对应的索引不存在*/
#define	UGS_THE_DATASET_NEED_NOT_BUILDINDEX_FOR_NOT_DIRTY _U("EDd004")	/*! 当前数据集索引不脏不需要创建索引*/

// 索引的相关操作错误
#define	UGS_ODBC_CREATEINDEX_FAILED             _U("EDe001")	/*! 创建索引失败*/
#define	UGS_ODBC_BULIDDYNAMIC_FAILED            _U("EDe002")	/*! 创建动态索引失败*/
#define	UGS_ODBC_BULID_DYNAMICINDEX_FAILED      _U("EDe003")	/*! 创建动态索引失败，原因%s*/
#define	UGS_ODBC_BULID_QTREE_INDEX_FAILED       _U("EDe004")	/*! 创建四叉树索引失败，原因%s*/
#define	UGS_ODBC_BUILD_TILE_DATASET_FAILED      _U("EDe005")	/*! 创建图幅索引失败*/
#define	UGS_ODBC_BULIDTILE_FAILED               _U("EDe006")	/*! 创建图幅索引失败，原因%s*/
#define	UGS_ODBC_VECTOR_CREATERTREEINDEX_FAILED _U("EDe007")	/*! 矢量数据集创建R树索引失败*/
#define	UGS_ODBC_BULID_RETREEINDEX_GET_RTREE_NODEID_FAILED _U("EDe008")	/*! 创建R树索引时，获取叶子结点ID失败*/
#define	UGS_FAILED_TO_CREATE_TILE_SUBDATASET    _U("EDe009")	/*! 创建图幅子数据集失败*/
#define	UGS_ODBC_UPDATE_LIBTILE_VERSION_FAILED  _U("EDe010")	/*! 更新图幅索引失败*/
#define	UGS_ODBC_UPDATE_RTREE_ITEM_ADD_FAILED   _U("EDe011")	/*! 更新R树索引叶结点失败*/
#define	UGS_ODBC_UPDATE_DYNAMICINDEX_FAILED     _U("EDe012")	/*! 更新动态索引失败*/
#define	UGS_ODBC_UPDATE_QTREEINDEX_FAILED       _U("EDe013")	/*! 更新四叉树索引失败*/
#define	UGS_CANNOT_UPDATE_INDEX_FOR_LIBID_NOT_EXIST _U("EDe014")	/*! 更新图幅索引的图幅信息失败*/
#define	UGS_ODBC_GETLIBTILE_ID_FAILED           _U("EDe015")	/*! 获取图幅ID失败*/
#define	UGS_NOT_TILE_INDEX_CANNOT_GET_TITLE_ID  _U("EDe016")	/*! 当前索引非图幅索引，不能获取图幅ID*/
#define	UGS_ODBC_RTREEINDEX_GET_NODES_FAILED    _U("EDe017")	/*! R树索引获取叶子结点失败*/
#define	UGS_FAILED_TO_GET_TILE_SUBDATASET       _U("EDe018")	/*! 获取图幅索引子数据集失败*/
#define	UGS_FAILED_TO_GET_TILE_DATASET          _U("EDe019")	/*! 获取图幅索引数据集失败*/
#define	UGS_FAILED_TO_QUERY_TITLE_DATASET       _U("EDe020")	/*! 查询图幅索引数据集失败*/
#define	UGS_IDXTILE_DOESNOT_SUPPORT_REBUILD     _U("EDe021")	/*! 图幅索引不支持重建*/
#define	UGS_ODBC_LOADRTREELEAF_FAILED           _U("EDe022")	/*! 加载R树索引叶子节点失败*/
#define	UGS_FAILED_TO_SEARCH_INDEX              _U("EDe023")	/*! 查找索引失败*/
#define	UGS_ODBC_SAVEINDEXINFO_FAILED           _U("EDe024")	/*! 保存索引信息失败*/
#define	UGS_TILEINDEX_FAILED_TO_UNREGISTER      _U("EDe025")	/*! 图幅索引反注册失败*/
#define	UGS_FAILED_TO_GET_DEFAULT_INDEX_PARAMETER _U("EDe026")	/*! 获取默认索引参数失败*/
#define	UGS_FAILED_TO_CLEARRTREEINDEX           _U("EDe027")	/*! 删除R树索引失败*/
#define	UGS_FAILED_TO_DELETE_INDEX_LD           _U("EDe028")	/*! 删除索引[%ld]失败*/



// 范围的值非法，包括宽度、高度、面积等
#define	UGS_HEIGHT_OR_WIDTH_LESSTHAN_TEN        _U("EEa001")	/*! 参数非法：高度或者宽度必须大于等于10*/
#define	UGS_HEIGHT_OR_WIDTH_LESSTHAN_ONE        _U("EEa002")	/*! 参数非法：高度或者宽度必须大于等于1*/
#define	UGS_RECTANGLE_HEIGHT_OR_WIDTH_LESSTHAN_TWO _U("EEa003")	/*! 参数非法：矩形的宽度或者高度小于2*/
#define	UGS_WIDTH_OVERRUN                       _U("EEa004")	/*! 参数非法：宽度大于32767*/
#define	UGS_TRANS_HEIGHT_OR_WIDTH_IS_ZERO       _U("EEa005")	/*! 参数非法：半透明高度或宽度为0*/
#define	UGS_BIT_HEIGHT_OR_WIDTH_IS_ZERO         _U("EEa006")	/*! 参数非法：位图高度或者宽度为0*/
#define	UGS_RECTANGLE_WIDTH_MUST_MORETHAN_ZERO  _U("EEa007")	/*! 矩形的宽必须大于0*/
#define	UGS_RECTANGLE_HEIGHT_MUST_MORETHAN_ZERO _U("EEa008")	/*! 矩形的高必须大于0*/
#define	RECTANGLE_AREA_IS_NULL                  _U("EEa009")	/*! 矩形面积必须大于0*/
#define	UGS_TEXT_HEIGHT_IS_ZERO                 _U("EEa010")	/*! 文本风格高度必须大于零*/
#define	UGS_TEXT_WIDTH_OVERRUN                  _U("EEa011")	/*! 字体宽度大于最大可视大小*/
#define	UGS_TEXT_HEIGHT_OVERRUN                 _U("EEa012")	/*! 字体高度小于最小可视大小*/
#define	UGS_THEMELABEL_TEXT_WIDTH_OVERRUN       _U("EEa013")	/*! 字体宽度超出范围*/
#define	UGS_THEMEGRAPH_GRAPH_IN_HITTEST_TOO_BIG _U("EEa014")	/*! 图像范围大于最大值*/
#define	UGS_THEMEGRAPH_GRAPH_IN_HITTEST_TOO_SMALL _U("EEa015")	/*! 图像范围小于最小值*/
#define	UGS_MAP_HEIGHT_OR_WIDTH_IS_ZERO         _U("EEa016")	/*! 锁定地图范围的高度或者宽度为0*/
#define	UGS_DRAWING_PARAM_DISPLAY_BOUND_LESSTHAN_ZERO _U("EEa017")	/*! 点符号绘制时，绘制参数显示范围小于0*/
#define	UGS_IAMGE_SIZE_OVERTOP_WHEN_FILLSYMBOL_ROMANCE _U("EEa018")	/*! 填充符号渲染时，图像大小超出合理范围*/
#define	UGS_CANNOT_WORK_FOR_GEOBOUNDS_AREA_IS_NULL _U("EEa019")	/*! 几何对象的外接矩形面积为0*/
#define	UGS_ARC_LENGTH_LESSTHAN_ZERO            _U("EEa020")	/*! 弧段的长度小于0*/
#define	UGS_IMAGE_MSG_ERROR_DATA                _U("EEa021")	/*! 栅格/影像数据集的长或宽必须大于0*/
#define	UGS_BUFFER_ANALYSIS_RADIUS_IS_ZERO      _U("EEa022")	/*! 缓冲半径必须大于0*/
#define	UGS_RESMAPLE_INTERVAL_MUST_MORETHAN_ZERO _U("EEa023")	/*! 重采样间隔必须大于0*/
#define	UGS_ROUNDRECT_ANGLE_SHOULD_MORETHAN_ZERO _U("EEa024")	/*! 参数错误：圆角矩形的圆角弧度必须大于等于0*/
#define	UGS_ELLIPSE_MAJORANDMINOR_AXIS_SHOULD_MORETHAN_ZERO _U("EEa025")	/*! 参数错误：椭圆的长短轴都必须大于0*/
#define	UGS_GEOPIE_MAJOR_OR_MINOR_AXIS_SHOULD_MORETHAN_ZERO _U("EEa026")	/*! 参数错误：扇形的半径应大于0*/
#define	UGS_COORDINATE_OVERRUN                  _U("EEa027")	/*! 坐标值超出图幅范围*/
#define	UGS_GRADIENT_INTERVAL_IS_ZERO           _U("EEa028")	/*! 参数非法：渐变线的间距为零*/
#define	UGS_PARALLEL_LINE_INTERVAL_IS_ZERO      _U("EEa029")	/*! 参数非法：水平线间距为零*/
#define	UGS_RADIUS_IS_ZERO                      _U("EEa030")	/*! 参数非法：半径必须大于0*/
#define	UGS_POINT_COUNTS_IS_ZERO                _U("EEa031")	/*! 参数非法：点个数必须大于零*/
#define	UGS_INVALID_PARAM                       _U("EEa032")	/*! 参数非法*/
#define	UGS_SYMBOL_SIZE_LESS_THAN_ZERO          _U("EEa033")	/*! 参数非法：符号的大小小于0*/
#define	UGS_INVALID_COORDINATE_AREA             _U("EEa034")	/*! 经纬坐标下的范围不正确*/
#define	UGS_CHOOSEFOCAL_TOOBIG                  _U("EEa035")	/*! 选择邻域过大*/
#define	UGS_OVERLAPPED_RANGE                    _U("EEa036")	/*! 区间重叠*/

// 参数的个数非法，包括点、图层、弧段、记录等的个数
#define	UGS_LAYER_COUNT_LESSTHAN_ONE            _U("EEb001")	/*! 图层个数为0*/
#define	UGS_INSERT_LAYER_COUNT_IS_OVERRUN       _U("EEb002")	/*! 插入层数超过允许最大层数*/
#define	UGS_LINE_EXTENT_COUNT_MORETHAN_FIVE     _U("EEb003")	/*! 线性扩展个数不能大于5*/
#define	UGS_NODE_COUNT_LESSTHAN_TWO             _U("EEb004")	/*! 点的个数不能少于2个*/
#define	UGS_TRACE_NODE_LESSTHAN_TWO             _U("EEb005")	/*! 追踪点个数不能少于2个*/
#define	UGS_STYLE_COUNT_INVALID                 _U("EEb006")	/*! 参数非法：风格个数应该在0~256之间*/
#define	UGS_NODE_COUNT_LESSTHAN_ONE             _U("EEb007")	/*! 节点个数不能少于1*/
#define	UGS_PATH_COUNT_LESSTHAN_ZERO            _U("EEb008")	/*! 路径个数不能小于0*/
#define	UGS_ROUTE_COUNT_LESSTHAN_ZERO           _U("EEb009")	/*! 路由个数不能小于0*/
#define	UGS_MEMORY_DATASOURCE_COUNT_IS_ZERO     _U("EEb010")	/*! 内存数据源的个数为0*/
#define	UGS_BUFFER_ANALYSIS_OBJECTS_COUNT_IS_0  _U("EEb011")	/*! 对象个数为0*/
#define	UGS_CENTERPOINT_COUNT_LESSTHAN_ZERO     _U("EEb012")	/*! 中心点个数不能少于0*/
#define	UGS_CENTER_POINTER_DEMANDE_LESSTHAN_ZERO _U("EEb013")	/*! 中心需求点个数不能小于0*/
#define	UGS_LOCATION_COUNT_LESSTHAN_ZERO        _U("EEb014")	/*! 选址分区个数不能小于0*/
#define	UGS_COUNT_LESSTHAN_ONE                  _U("EEb015")	/*! 参数非法：个数不能小于等于0*/
#define	UGS_SYMLIB_SYMBOL_COUNT_LESSTHAN_ZERO   _U("EEb016")	/*! 符号库中符号总数不能小于0*/
#define	UGS_POINT_COUNT_LESSTHAN_ZERO           _U("EEb017")	/*! 点的个数不能小于0*/
#define	UGS_REGION_COUNT_LESSTHAN_ZERO          _U("EEb018")	/*! 多边形的个数小于0*/
#define	UGS_RECORD_COUNT_IS_ZERO                _U("EEb019")	/*! 记录个数不能为0*/
#define	UGS_FIELD_COUNT_IS_NULL_AND_ISNOT_EVEN  _U("EEb020")	/*! 参数非法：字段个数应该为偶数且不为0*/
#define	UGS_FILLSYMBOL_SUBSYMBOL_COUNT_IS_ZERO  _U("EEb021")	/*! 参数非法：填充符号子符号个数不能为0*/
#define	UGS_THEME_COUNT_LESSTHAN_ONE_REMOVE     _U("EEb022")	/*! 参数非法：移除个数必须大于0*/
#define	UGS_WRONG_NODE_COUNT                    _U("EEb023")	/*! 节点个数错误*/
#define	UGS_EDGEFIELD_IS_NULL                   _U("EEb024")	/*! 弧段个数为空*/
#define	UGS_NODE_COUNT_INFO_NOT_MATCH           _U("EEb025")	/*! 节点信息个数错误*/
#define	UGS_INVALID_GEO_FOR_SUBCOUNT_EQUAL_ZERO _U("EEb026")	/*! 参数非法：几何对象的子对象个数为零*/
#define	UGS_FIELDS_LESSTHAN_TWO                 _U("EEb027")	/*! 字段个数小于2*/
#define	UGS_FIELD_COUNT_IS_ZERO                 _U("EEb028")	/*! 字段个数为0*/
#define	UGS_ARRAY_SIZE_IS_ONE                   _U("EEb029")	/*! 数组长度为1*/
#define	UGS_INVALID_ARRAY_SIZE                  _U("EEb030")	/*! 数组长度必须大于0*/
#define	UGS_RECORDSET_COUNT_IS_ZERO             _U("EEb031")	/*! 记录集个数为0*/
#define	UGS_INVALID_DATASET_COUNT               _U("EEb033")	/*! 数据集个数非法*/
#define	UGS_SELECTION_DELETE_NONE               _U("EEb034")	/*! 需要删除记录数为0*/
#define	UGS_ARC_SELECTIONCOUNT_IS_NULL          _U("EEb035")	/*! 选择的弧段数为0*/
#define	UGS_INVALID_MERGE_BUSSTOP_ID            _U("EEb036")	/*! 归并站点ID不能小于0*/
#define	UGS_BLOCKCOUNT_ERROR                    _U("EEb037")	/*! 分块数目不对*/
#define	UGS_NOT_ENOUGH_SEGMENTS                 _U("EEb038")	/*! 分段数必须大于等于1*/
#define	UGS_BAND_COUNT_IS_ZERO                  _U("EEb039")	/*! 波段数为0*/
#define	UGS_HITGEO_COUNT_IS_ZERO                _U("EEb040")	/*! 对象选中个数为0*/
#define	UGS_HITGEO_COUNT_MORETHAN_TWO           _U("EEb041")	/*! 对象选中个数不应大于2*/
#define	UGS_HITGEO_COUNT_MORETHAN_ONE           _U("EEb042")	/*! 对象选中个数不应大于1*/
#define	UGS_HITGEO_COUNT_LESSTHAN_THREE         _U("EEb043")	/*! 对象选中个数少于3个*/
#define	UGS_ONLY_ONE_ARC                        _U("EEb044")	/*! 弧段个数为1*/

// 普通参数值非法
#define	UGS_INVLIAD_ARC                         _U("EEc001")	/*! 网络弧段ID非法：ID值小于0或者大于弧段总数*/
#define	UGS_LOADING_PARAM_ILLEGAL               _U("EEc002")	/*! 传入参数非法：nIndex值小于0或者大于字段总数*/
#define	UGS_SERVICE_RADIUS_TOO_SMALL            _U("EEc003")	/*! 参数非法：服务区半径小于最小值1e-10*/
#define	UGS_INVALID_BUSLINE_ID                  _U("EEc004")	/*! 参数非法：线路ID小于0*/
#define	UGS_INVALID_NODE_ID                     _U("EEc005")	/*! 参数非法：节点的ID小于0*/
#define	UGS_THEMELABEL_SEGMENT_LESSTHAN_TWO     _U("EEc006")	/*! 参数非法：段值必须大于等于2*/
#define	UGS_SEGEMENT_VALUE_IS_ZERO              _U("EEc007")	/*! 参数非法：段值小于等于0*/
#define	UGS_MAX_IS_ZERO                         _U("EEc008")	/*! 参数非法：最大值为0*/
#define	UGS_TOLERANCE_TOO_SMALL                 _U("EEc009")	/*! 容限不能小于1.0e-10*/
#define	UGS_INVALID_STARTNODE_EQUAL_ENDNODE_ANALYSE_FAILED _U("EEc010")	/*! 传入ID(%d)非法：起始点与终止点是同一个点*/
#define	UGS_INVLAID_STARTPOINT_AND_ENDPOINT     _U("EEc011")	/*! 起始点和终止点ID不能小于0*/
#define	UGS_STRARCID_IS_NULL                    _U("EEc012")	/*! 网络弧段的ID为空*/
#define	UGS_INVALID_BUSSTOP_ID                  _U("EEc013")	/*! 站点ID非法*/
#define	UGS_SMID_LESSTHAN_ZERO                  _U("EEc014")	/*! 系统ID小于零*/
#define	UGS_INVALID_VALUE                       _U("EEc015")	/*! 非法值*/
#define	UGS_THEMEGRAPH_TO_GEOMETRY_HAVE_NEGAITIVE_VALUE _U("EEc016")	/*! 统计值必须大于等于0*/
#define	UGS_COUNT_IS_NULL                       _U("EEc017")	/*! 参数非法：单词的词频为0*/
#define	UGS_INVALID_PARAM_FOR_INVALID_M         _U("EEc018")	/*! 参数错误：无效的M值计算枚举变量*/
#define	UGS_BUFFER_ANALYSIS_SEMICIRCLESEMENT_NOT_CORRET _U("EEc019")	/*! 参数非法：拟合弧段小于4或大于200*/
#define	UGS_SCALE_IS_ZERO                       _U("EEc020")	/*! 比例尺为零*/
#define	UGS_PRINT_SCALE_IS_ZERO                 _U("EEc021")	/*! 打印比例尺为零*/
#define	UGS_DRAW_PARAM_SCALE_IS_ZERO            _U("EEc022")	/*! 绘制参数比例尺为零*/
#define	UGS_MAP_SCALE_IS_ZERO                   _U("EEc023")	/*! 地图比例尺为零*/
#define	UGS_INVALID_DATASET_SIZE                _U("EEc024")	/*! 数据集长度非法*/
#define	UGS_CHAR_IS_NULL                        _U("EEc025")	/*! 字符为空*/
#define	UGS_INTERNAL_PARAM_NOT_INITIALIZE       _U("EEc026")	/*! 内部参量还未初始化*/
#define	UGS_COMPRESS_PARAM_INVALID              _U("EEc027")	/*! 压缩文件参数非法*/
#define	UGS_PARAM_IS_EMPTY_S                    _U("EEc028")	/*! 参数%s为空*/
#define	UGS_PARAM_IS_NOT_SETTED                 _U("EEc029")	/*! 函数(%s)未设置参数(%s)*/
#define	UGS_NOT_SUPPORT_TO_THE_TYPE             _U("EEc030")	/*! 不支持导入为%s类型文件*/
#define	UGS_INVALID_PAGECOUNT                   _U("EEc031")	/*! 分配的页面数不合法，必须在0~1024范围内*/
#define	UGS_S_FAILED_TO_GET_S                   _U("EEc032")	/*! (%s)获取(%s)失败*/
#define	UGS_CONFLICT_CONTROLRANGE               _U("EEc033")	/*! 无值或背景范围与指定值范围有冲突*/
#define	UGS_OUTERRADIUS_SMALLERThAN_INNERRADIUS _U("EEc034")	/*! 输入的外半径值要大于内半径的值*/

// 参数的类型不匹配的相关错误信息
#define	UGS_OVERLAP_TYPE_NOT_MATCH              _U("EEd001")	/*! 叠加分析类型不匹配*/
#define	UGS_NETWORK_NODEDT_TYPE_ERROR           _U("EEd002")	/*! 网络点数据集类型非法*/
#define	UGS_INVALID_NUMBER                      _U("EEd003")	/*! 非法的整型数据*/
#define	UGS_CANNOT_FIND_MATCHED_END_POINT       _U("EEd004")	/*! 没有匹配的终止点*/
#define	UGS_CANNOT_FIND_MATCHED_START_POINT     _U("EEd005")	/*! 没有匹配的起始点*/
#define	UGS_ENDPOINT_IS_BARRIERNODE             _U("EEd006")	/*! 终止节点是障碍点*/
#define	UGS_STARTPOINT_IS_BARRIERNODE           _U("EEd007")	/*! 起始点是障碍点*/
#define	UGS_INVALID_ENDPOINT_M                  _U("EEd008")	/*! 终点M值无效*/
#define	UGS_INVALID_STARTPOINT_M                _U("EEd009")	/*! 起点M值无效*/
#define	UGS_GRID_TYPE_UNCONFORMITY              _U("EEd010")	/*! 网格化类型非法*/
#define	UGS_INVALID_ENUM                        _U("EEd011")	/*! 无效的枚举变量*/
#define	UGS_FIELD_TYPE_NOT_MATCH                _U("EEd012")	/*! 字段类型不匹配*/
#define	UGS_INVALID_PICTURE_TYPE                _U("EEd013")	/*! 图形对象非法*/

// 主要描述多个参数关系的逻辑错误，包括类型转换
#define	UGS_DRWING_STARTPOINT_AND_ENDPOINT_IS_THE_SAME_POINT _U("EEe001")	/*! 线的起点和终点不能为同一点*/
#define	UGS_ORIGINALDATASET_ISNOT_OVERLAP_WITH_TARGETDATASET _U("EEe002")	/*! 源数据集与目标数据集的范围不一致*/
#define	UGS_TWO_NODES_SAME_ID                   _U("EEe003")	/*! 两个点ID相同*/
#define	UGS_TWO_ARRAY_HAVE_DIFFERNT_SIZE        _U("EEe004")	/*! 两数组大小不同*/
#define	UGS_TWO_POINTS_CANNOT_MIRROR            _U("EEe005")	/*! 两点相同，无法镜像*/
#define	UGS_NODE_COUNT_NOT_EQUAL_ARC_COUNT      _U("EEe006")	/*! 点和弧段个数不一致*/
#define	UGS_FAILED_TO_CONVERT_VARIANT_TO_DOUBLE _U("EEe007")	/*! 变量转换为双精度类型失败*/
#define	UGS_OVERLAYANALYSIS_DATASET_TYPE_NOT_MATCH _U("EEe008")	/*! 叠加分析数据集类型不匹配*/
#define	UGS_CHECKING_AND_CHECKED_DATASET_CANNOT_BE_SAME_DATASET _U("EEe009")	/*! 检查数据集和被检查数据集不能为同一数据集*/
#define	UGS_SET_ID_SAME_AS_SELF_ID              _U("EEe010")	/*! 设置的ID与自身ID相等*/
#define	UGS_DTM_MSG_NO_REGION_OVERLAY           _U("EEe011")	/*! 数据集没有范围重叠*/
#define	UGS_SAME_DATASOURCE                     _U("EEe012")	/*! 两个数据源相同*/
#define	UGS_STARTPOINT_AND_ENDPOINT_NOT_CONNECTED _U("EEe013")	/*! 起点和终点不连通*/
#define	UGS_STARTPOINT_AND_ENDPOINT_IS_SAME     _U("EEe014")	/*! 起点和终点相同*/
#define	UGS_DUPLICATED_PARAMETERS_FOUND         _U("EEe015")	/*! 各个参数不能相同*/
#define	UGS_TYPE_MISMATCH_BETWEEN_RS_AND_DT     _U("EEe016")	/*! 数据集和记录集的类型不匹配*/
#define	UGS_MISMATCH_SOURCE_DT_AND_TARGET_DT    _U("EEe017")	/*! 源数据集和目标数据集的类型必须相同*/
#define	UGS_MISMATCH_DATASET_TYPE               _U("EEe018")	/*! 数据集类型不匹配*/
#define	UGS_NODE_COUNT_DIFFERENT_WITH_SERVICE_DISTANCE _U("EEe019")	/*! 节点个数和服务距离个数不一致*/
#define	UGS_NODE_COUNT_DIFFERENT_WITH_SERVICE   _U("EEe020")	/*! 节点的个数和服务分析个数不一致*/
#define	UGS_CENTERPOINT_LESSTHAN_SERVICE_COUNT  _U("EEe021")	/*! 中心点个数小于服务区分析个数*/
#define	UGS_DATASET_AND_FIELD_SIZE_UNLIKENESS   _U("EEe022")	/*! 数据集和字段数组大小不相等*/
#define	UGS_COUNT_DIFFERNT_WITH_WORD            _U("EEe023")	/*! 大小和词的的个数不一致*/
#define	UGS_DIFFERENT_DATASOURCE                _U("EEe024")	/*! 两个数据源不相同*/

// 范围为空，包括矩形范围、地图的范围、设备范围、裁剪范围等
#define	UGS_OUTPUT_MAP_BOUND_IS_NULL            _U("EEf001")	/*! 输出地图范围为空*/
#define	UGS_RECTANGLE_IS_NULL                   _U("EEf002")	/*! 矩形为空*/
#define	UGS_MAP_BOUNDS_IS_NULL                  _U("EEf003")	/*! 地图范围为空*/
#define	UGS_MAP_OR_EQUIPMENT_BOUNDS_IS_NULL     _U("EEf004")	/*! 设备范围或者地图范围为空*/
#define	UGS_CLIP_RECTANGLE_IS_NULL              _U("EEf005")	/*! 裁剪区域矩形为空*/
#define	UGS_CLIP_REGION_IS_NULL                 _U("EEf006")	/*! 裁剪区域为空*/
#define	UGS_GRADIENT_RECTANGLE_IS_NULL          _U("EEf007")	/*! 渐变矩形为空*/
#define	UGS_GET_FILLSYMPARAM_RECTANGLE_IS_NULL  _U("EEf008")	/*! 获取的填充矩形为空*/
#define	UGS_DRAW_POLYGON_BOUND_RECTANGLE_IS_NULL_WHEN_DRAW_FILLSYM _U("EEf009")	/*! 绘制的多边形外界矩形为空*/
#define	UGS_SYMBOL_INVALID_RECT                 _U("EEf010")	/*! 非法矩形*/
#define	UGS_THIS_MAPBREADTH_HAS_NODATA          _U("EEf011")	/*! 此图幅范围内没有数据*/

// 数据集、记录集、数据源等指针为空
#define	UGS_DATASOURCE_POINTER_NULL             _U("EEg001")	/*! 数据源指针为空*/
#define	UGS_DATASET_POINTER_NULL                _U("EEg002")	/*! 数据集指针为空*/
#define	UGS_SUBDATASET_IS_NULL                  _U("EEg003")	/*! 子数据集指针为空*/
#define	UGS_RTREE_POINTER_IS_NULL               _U("EEg004")	/*! R树指针为空*/
#define	UGS_CENTERPOINTS_DT_IS_NULL             _U("EEg005")	/*! 中心点数据集指针为空*/
#define	UGS_NETWORK_IS_NULL                     _U("EEg006")	/*! 网络数据集指针为空*/
#define	UGS_DIRTY_DATASET_IS_NULL               _U("EEg007")	/*! 脏区数据集为空*/
#define	UGS_DTDMARC_IS_NULL                     _U("EEg008")	/*! 需求弧段数据集为空*/
#define	UGS_DTDMNODES_IS_NULL                   _U("EEg009")	/*! 需求点数据集为空*/
#define	UGS_DTTRN_IS_NULL                       _U("EEg010")	/*! 转向表数据集为空*/
#define	UGS_LINE_DATASET_POINTER_IS_NULL        _U("EEg011")	/*! 线数据集指针为空*/
#define	UGS_REGION_DATASET_POINTER_IS_NULL      _U("EEg012")	/*! 面数据集指针为空*/
#define	UGS_TOPO_DATASET_POINTER_IS_NULL        _U("EEg013")	/*! 拓扑数据集指针为空*/
#define	UGS_IMAGE_POINTER_IS_NULL               _U("EEg014")	/*! 影像数据集指针为空*/
#define	UGS_INVALID_BUSNETWORK                  _U("EEg015")	/*! 公交网络数据集为空*/
#define	UGS_GOAL_DATASOURCE_POINTER_IS_NULL     _U("EEg016")	/*! 获取的GDAL数据源指针为空*/
#define	UGS_OGR_DATASOURCE_POINTER_IS_NULL      _U("EEg017")	/*! 获取的OGR数据源指针为空*/
#define	UGS_GET_OGRLAYER_POINTER_IS_NULL        _U("EEg018")	/*! 获取OGRLayer指针为空*/
#define	UGS_OGRDRIVER_POINTER_IS_NULL           _U("EEg019")	/*! OGRDriver指针为空*/
#define	UGS_FILE_POINTER_NULL                   _U("EEg020")	/*! 文件指针为空*/
#define	UGS_NODE_POINTER_IS_NULL                _U("EEg021")	/*! 结点指针为空*/
#define	UGS_ENG_EMPTY_RS                        _U("EEg022")	/*! 当前记录集为空*/
#define	UGS_RECORDSET_IS_EMPTY                  _U("EEg023")	/*! 记录集为空，即记录数为0*/
#define	UGS_RECORDSET_POINTER_IS_NULL           _U("EEg024")	/*! 记录集指针为空*/
#define	UGS_ORIGINAL_RECORDSET_IS_NULL          _U("EEg025")	/*! 原记录集为空*/
#define	UGS_GET_RECORDSET_IS_NULL               _U("EEg026")	/*! 获取记录集为空*/
#define	UGS_NETWORK_RECORDSET_IS_NULL           _U("EEg027")	/*! 网络记录集为空*/
#define	UGS_BUSLINE_RECORDSET_IS_NULL           _U("EEg028")	/*! 线路记录集为空*/
#define	UGS_BUSSTOP_RECORDSET_IS_NULL           _U("EEg029")	/*! 站点记录集为空*/
#define	UGS_SELECTION_RECORDSET_POINTER_IS_NULL _U("EEg030")	/*! 选择集中记录集指针为空*/
#define	UGS_APPENDING_DATASET_POINTER_IS_NULL   _U("EEg031")	/*! 追加的数据集指针为空*/
#define	UGS_AIM_DATASET_IS_NULL                 _U("EEg032")	/*! 目标数据集为空*/

// 整型、字符串等变量为空或指针为空
#define	UGS_DIVMATRIX_POINTER_NULL              _U("EEh001")	/*! 归约矩阵指针为空*/
#define	UGS_PARAM_INVALID_FOR_POINTS_POINTER_IS_NULL _U("EEh002")	/*! 参数错误：点串指针为空*/
#define	UGS_PDRAWPARAM_IS_NULL                  _U("EEh003")	/*! 绘制参数为空*/
#define	UGS_DRAWING_POINTER_IS_NULL             _U("EEh004")	/*! 绘制参数指针为空*/
#define	UGS_PDRAWCACHE_IS_NULL                  _U("EEh005")	/*! 绘制缓存为空*/
#define	UGS_ADDRESS_IS_NULL                     _U("EEh006")	/*! 地址串为空*/
#define	UGS_XML_INFO_IS_NULL                    _U("EEh007")	/*! XML信息串为空*/
#define	UGS_NODE_POINTER                        _U("EEh008")	/*! 节点指针为空*/
#define	UGS_THE_FIRST_CHAR_OF_WORD_IS_NULL      _U("EEh009")	/*! 串首位置为空*/
#define	UGS_NODE_IS_NULL                        _U("EEh010")	/*! 网络节点为空*/
#define	UGS_NODE_TYPE_IS_NULL                   _U("EEh011")	/*! 节点类型为空*/
#define	UGS_WORD_POINTER_IS_NULL                _U("EEh012")	/*! 词串指针为空*/
#define	UGS_DISTANCE_POINTER_IS_NULL            _U("EEh013")	/*! 距离指针为空*/
#define	UGS_WORD_IS_NULL                        _U("EEh014")	/*! 词语为空*/
#define	UGS_PARAMETERS_HAVE_NULL_POINTER        _U("EEh015")	/*! 传进来的参数的指针为空*/
#define	UGS_COST_MARK_NULL                      _U("EEh016")	/*! 花费标记为空*/
#define	UGS_COST_IS_NULL                        _U("EEh017")	/*! 获取花费为空*/
#define	UGS_DEFINE_OPERATER_STRING_IS_NULL_OR_LENGTH_LESSTHAN_EIGHT _U("EEh018")	/*! 自定义算子字符串为空或长度小于八个字符*/
#define	UGS_SYMBOL_INVALID_TEXT                 _U("EEh019")	/*! 非法字串*/
#define	UGS_CENTERPOINT_TYPE_IS_NULL            _U("EEh020")	/*! 中心点类型为空*/
#define	UGS_PBYTE_POINTER_IS_NULL               _U("EEh021")	/*! pByte 指针为空*/
#define	UGS_STRING_IS_NULL                      _U("EEh022")	/*! 字符串为空*/
#define	UGS_ENTITY_IS_NULL                      _U("EEh023")	/*! 实体指针为空*/
#define	UGS_FEATURE_IS_NULL                     _U("EEh024")	/*! 对象Feature指针为空*/



// 数据或对象类型
#define	UGS_DATASET_ISNOT_CAD                   _U("EFa001")	/*! 指定数据集不是CAD数据集*/
#define	UGS_GEOMETRY_MUST_BE_REGION             _U("EFa002")	/*! 几何对象必须是面对象*/
#define	UGS_COPIED_GEO_TYPE_DIFFER_WITH_TARGET_GEO _U("EFa003")	/*! 被拷贝的几何对象与目标对象类型不一致*/
#define	UGS_NOT_SUPPORT_THIS_GEOMETRY_FORMAT    _U("EFa004")	/*! 不支持的几何对象类型*/
#define	UGS_INVALID_GEO                         _U("EFa005")	/*! 几何对象非法*/
#define	UGS_GEOMETRY_TYPE_INVALID               _U("EFa006")	/*! 几何对象类型非法*/
#define	UGS_GEOMETRY_IS_REGION                  _U("EFa007")	/*! 几何对象为面对像*/
#define	UGS_GEOMETRY_IS_LINE                    _U("EFa008")	/*! 几何对象为线对象*/
#define	UGS_GEOMETRY_IS_LINEM                   _U("EFa009")	/*! 几何对象为路由线对象*/
#define	UGS_GEOMETRY_IS_	COMPLEX                _U("EFa010")	/*! 几何对象为复杂对象*/
#define	UGS_CANNOT_MERGE_TWO_GEOMETRY_WITH_DIFFERNT_DIM _U("EFa011")	/*! 两个Geometry的维度不一致，无法合并*/
#define	UGS_GEOMETRY_UNKNOWN                    _U("EFa012")	/*! 无法识别的几何对象类型*/
#define	UGS_NOT_SUPPORT_THIS_TYPE_GEOMETRY      _U("EFa013")	/*! 不支持该类型对象*/
#define	UGS_INVALID_PARAM_FOR_INVALID_SHILD_OBJECT _U("EFa014")	/*! 非法的子对象*/
#define	UGS_ILLEGAL_DATA_FOR_GEOMETY_SIZE_LESSTHAN_EIGHT_BYTE _U("EFa015")	/*! 非法数据：几何对象的存储长度小于8字节*/
#define	UGS_DATA_UNEXPECTED                     _U("EFa016")	/*! 数据异常*/
#define	UGS_HAS_GAP_BETWEEN_LINE                _U("EFa017")	/*! 线段之间有间隔*/
#define	UGS_GEOMETRY_DIM_INVALID                _U("EFa018")	/*! 几何对象维度无效，仅支持点、线、面*/
#define	UGS_FAILED_TO_TRANSFER_GEOCURVE_TO_LINE _U("EFa019")	/*! 曲线转直线失败*/
#define	UGS_FAILED_CONVERT_POINT                _U("EFa020")	/*! 坐标点转换为节点失败*/

// 几何对象控制点
#define	UGS_PARAM_INVALID_FOR_NO_OVERLAPING_POINTS_SHOULD_MORETHAN_SIX _U("EFb001")	/*! 不重合的点数应大于6*/
#define	UGS_PARAM_INVALID_FOR_POINTS_SHOULD_MORETHAN_ZERO _U("EFb002")	/*! 点串应非空且个数大于0*/
#define	UGS_AT_LEAST_TWO_POINTS                 _U("EFb003")	/*! 控制点个数必须大于2*/
#define	UGS_AT_LEAST_THREE_POINTS               _U("EFb004")	/*! 控制点个数必须大于3*/
#define	UGS_POINT_COUNT_LESSTHAN_TWO            _U("EFb005")	/*! 点个数小于2*/
#define	UGS_AT_LEAST_FOUR_POINTS                _U("EFb006")	/*! 控制点个数必须大于4*/
#define	UGS_POINT_LACK                          _U("EFb007")	/*! 曲线控制点的个数不能少于6个*/
#define	UGS_GEOARC_INVALID_PARAM_FOR_THREE_POINTS_IN_ONE_LINE _U("EFb008")	/*! 参数非法：三个控制点成一条直线*/
#define	UGS_CONTRAL_POINTS_SHOULD_MORE_THAN_ZERO _U("EFb009")	/*! 参数非法：几何对象控制点个数应大于0*/
#define	UGS_XML_WRONG_FOR_GEOARC_PARAM_POINTS_LESS_THAN_THREE _U("EFb010")	/*! GeoArc的控制点应该大于等于3个*/
#define	UGS_XML_WRONG_FOR_GEOPOINT_COORDINATE_LESSTHAN_TWO _U("EFb012")	/*! GeoPoint的坐标少于2个*/
#define	UGS_REGION_NODES_NUMBER_BIGGER_THAN_MAX _U("EFb013")	/*! 面对象的节点数大于最大绘制节点数*/
#define	UGS_REGION_NEED_AT_LEAST_THREE_POINTS   _U("EFb014")	/*! 至少三点才能够面*/
#define	UGS_GEOLINE_NEED_MORETHAN_TWO_POINTS    _U("EFb015")	/*! 至少需要两点才能够成GeoLine*/
#define	UGS_GETTEXTPATHDATA_IS_EMPTY            _U("EFb016")	/*! 艺术字填充的笔画个数为空*/
#define	UGS_OUPUT_TO_PDF_NOT_SUPPORT_ARTEXT     _U("EFb017")	/*! pDF暂不支持输出艺术字*/
#define	UGS_UNKNOWN_ARTEXT_BOUNDS               _U("EFb018")	/*! 尚未确定艺术字的范围*/

// 矢量数据或几何对象为空
#define	UGS_GEOMETRY_POINTER_IS_NULL            _U("EFc001")	/*! 几何对象指针为空*/
#define	UGS_POINTS_POINTER_IS_NULL              _U("EFc002")	/*! 点串指针为空*/
#define	UGS_GEOMETRY_SETTED_IS_NULL             _U("EFc003")	/*! 设置的几何对象为空*/
#define	UGS_PGRAPHICS_IS_NULL                   _U("EFc005")	/*! pGraphics指针为空*/
#define	UGS_INVALID_PARAM_FOR_GEOMETRY_POINTER_IS_NULL _U("EFc006")	/*! Geometry指针为空*/
#define	UGS_GEOMETRY_ELEMENT_IS_NULL            _U("EFc007")	/*! 空几何元素*/
#define	UGS_GEOMETRY_GETTED_IS_NULL             _U("EFc008")	/*! 获取的几何对象为空*/
#define	UGS_NO_GEOMETRY_ELEMENT                 _U("EFc009")	/*! 没有几何对象数据*/
#define	UGS_CURRENT_CHILD_OBJECT_IS_NULL        _U("EFc010")	/*! 当前编辑子对象为空*/
#define	UGS_CURRENT_OBJECT_IS_NULL              _U("EFc011")	/*! 当前编辑对象为空*/
#define	UGS_CURRENT_DRAWING_BOUND_IS_NULL       _U("EFc012")	/*! 当前绘制范围为空*/
#define	UGS_CURRENT_DRAWING_GEO_IS_NULL         _U("EFc013")	/*! 当前绘制对象为空*/
#define	UGS_OBJECT_IS_NULL                      _U("EFc014")	/*! 对象为空*/
#define	UGS_IMPORT_POINT3D_IS_NULL              _U("EFc015")	/*! 三维坐标点为空*/
#define	UGS_INVALID_PARAM_FOR_IMPORT_GEOMETRY_NOT_NULL_AND_THE_SECOND_GEOMETRY_MUSTBE_REGION _U("EFc016")	/*! 传入几何对象指针必须非空，且第二个几何对象必须为面对像*/

// 矢量数据或几何对象相关的操作错误
#define	UGS_FAILED_TO_DRAW_REGION               _U("EFd001")	/*! 绘制面对象失败*/
#define	UGS_FAILED_TO_FORMAT_ARC                _U("EFd002")	/*! 参数化绘制弧段失败*/
#define	UGS_FAILED_TO_DRAW_UGPIE                _U("EFd003")	/*! 绘制扇形对象失败*/
#define	UGS_FAILED_TO_DRAW_PARALLEL_LINE        _U("EFd004")	/*! 绘制平行线失败*/
#define	UGS_FAILED_TO_DRAW_VERTICAL_LINE        _U("EFd005")	/*! 绘制垂直线失败*/
#define	UGS_UGDRAWCACHE_FAILED_TO_PREPARE       _U("EFd006")	/*! 准备绘制缓冲失败*/
#define	UGS_FAILED_TO_DRAW_COMPOUND             _U("EFd007")	/*! 绘制复合对象失败*/
#define	UGS_FAILED_TO_DRAW_ARC                  _U("EFd008")	/*! 构建圆弧对象失败*/
#define	UGS_CREATE_CLIP_REGION_FAILED           _U("EFd009")	/*! 创建裁剪区域失败*/
#define	UGS_FAILED_TO_CREATE_UGFONT             _U("EFd010")	/*! 创建字体类型失败*/
#define	UGS_ARRIVE_POLYLINE_END_WHOLE_POLYLINE_DRAWING_FINISH _U("EFd011")	/*! 已经到达折线的最后，整条折线绘制完毕*/
#define	UGS_WHETHER_JUST_FINISH_DRAWING_WHOLE_POLYLINE _U("EFd012")	/*! 先判断一下是否已经结束整个折线的绘制*/
#define	UGS_JUST_FINISH_DRAWING_WHOLE_POLYLINE_ _U("EFd013")	/*! 刚好结束整个折线的绘制*/
#define	UGS_FAILED_TO_MAKEPARALLELLINE          _U("EFd014")	/*! 生成平行线失败*/
#define	UGS_FAILED_TO_MAKESAMELINE              _U("EFd015")	/*! 生成复制线失败*/
#define	UGS_FAILED_TO_MAKEVERTICALLINE          _U("EFd016")	/*! 生成垂直线失败*/
#define	UGS_FAILED_TO_MAKEFIXANGLE              _U("EFd017")	/*! 根据两个点、角度、容限生成另外一个点失败*/
#define	UGS_FAILED_TO_MAKEFIXLENGTH             _U("EFd018")	/*! 在线上根据长度生成另外一个点失败*/
#define	UGS_FAILED_TO_GETPOINT                  _U("EFd019")	/*! 从捕捉元素中捕捉点失败*/
#define	UGS_FAILED_TO_SETPOINT                  _U("EFd020")	/*! 将捕捉到的点加到捕捉元素中失败*/
#define	UGS_FAILED_TO_SNAP                      _U("EFd021")	/*! 捕捉失败*/
#define	UGS_THERE_IS_NO_SANPPOINT_IN_BUFFER     _U("EFd022")	/*! Buffer中没有捕捉点对象*/
#define	UGS_THERE_IS_NO_SANPLINE_IN_BUFFER      _U("EFd023")	/*! Buffer中没有捕捉线对象*/
#define	UGS_FAILED_TO__BREAK                    _U("EFd024")	/*! 打断线失败*/
#define	UGS_FAILED_TO_SPLITGEOCOMPOUND          _U("EFd025")	/*! 拆分复合对象失败*/
#define	UGS_FAILED_TO_UNGROUP_THE_COMPOUND      _U("EFd026")	/*! 打散复合对象失败*/
#define	UGS_FAILED_TO_MERGE                     _U("EFd027")	/*! 对象合并失败*/
#define	UGS_FAILED_TO_DRAW_HITTESTGEOTEXT       _U("EFd028")	/*! 选中文本失败*/
#define	UGS_FAILED_TO_JUDGE_HITTESTGEOTEXT      _U("EFd029")	/*! 判断文本对象是否被选中失败*/
#define	UGS_FAILED_TO_INITIALIZE_TXT_STYLE      _U("EFd030")	/*! 初始化文本风格失败*/
#define	UGS_FAILED_TO_CALCULATE_BOUND           _U("EFd031")	/*! 计算选中对象总范围失败*/
#define	UGS_FAILED_TO_SELECT_WITH_REGION        _U("EFd032")	/*! 拉框选择失败*/
#define	UGS_FAILED_TO_COMPLETE_EDITING          _U("EFd033")	/*! 完成编辑动作失败*/
#define	UGS_FAILED_TO_SAVE_EDIT_GEO             _U("EFd034")	/*! 保存编辑对象失败*/
#define	UGS_FAILED_TO_SETACCESSIBILITYACTIONPOINTMODE _U("EFd035")	/*! 设置结点编辑模式失败*/
#define	UGS_FAILED_TO_REFRESH_GEO               _U("EFd036")	/*! 刷新对象失败*/
#define	UGS_GET_GEOMETRY_OBJECTS_FAILED         _U("EFd037")	/*! 获取几何对象失败*/
#define	UGS_FAILED_TO_READ_ONE_GEOMETRY         _U("EFd038")	/*! 读取几何对象失败*/
#define	UGS_FAILED_TO_ADD_GEO                   _U("EFd039")	/*! 添加几何对象失败*/
#define	UGS_TRACKINGLAYER_CANNOT_USE_THE_ADDING_GEO _U("EFd040")	/*! 跟踪层添加几何对象失败*/
#define	UGS_FAILED_TO_INSERTPOINTTOGEOMETRY     _U("EFd041")	/*! 添加控制点到当前对象中失败*/
#define	UGS_ODBC_SETMAXGEOSIZE_FAILED           _U("EFd042")	/*! 设置最大几何对象的大小失败*/
#define	UGS_FAILED_TO_ISREDOTOOLENABLE          _U("EFd043")	/*! 判断是否可以恢复上一步操作失败*/
#define	UGS_FAILED_TO_ISUNDOTOOLENABLE          _U("EFd044")	/*! 判断是否可以撤销上一步操作失败*/
#define	UGS_FAILED_TO_CALCULATE_ASSISTANT_POINT _U("EFd045")	/*! 计算辅助线辅助点失败*/
#define	UGS_ODBC_COMPUTE_BOUNDS_FAILED          _U("EFd046")	/*! 计算外接矩形失败*/
#define	UGS_LINE_FAILED_TO_FIX_ANGLE            _U("EFd047")	/*! 同一线段成固定角度失败*/
#define	UGS_LINE_FAILED_TO_FIX_LENGTH           _U("EFd048")	/*! 固定长度失败*/
#define	UGS_LINE_FAILED_TO_ON_POINT             _U("EFd049")	/*! 线经过点失败*/
#define	UGS_POINT_NOT_AT_LINE_EXTEND            _U("EFd050")	/*! 点不在延长线上*/
#define	UGS_POINT_NOT_AT_LINE_MIDDLE            _U("EFd051")	/*! 点不在线中点*/
#define	UGS_POINT_NOT_AT_LINE                   _U("EFd052")	/*! 点不在线上*/
#define	UGS_POINT_NOT_AT_LINE_SE_POINT          _U("EFd053")	/*! 点不在线端点上*/
#define	UGS_FAILED_TO_GET_POINTS                _U("EFd054")	/*! 获取点串失败*/
#define	UGS_FAILED_TO_GET_SPATIAL_DATA          _U("EFd055")	/*! 获取空间数据失败*/
#define	UGS_FAILED_TO_GET_SPATIAL_POINTS        _U("EFd056")	/*! 获取空间点串失败*/
#define	UGS_FAILED_TO_GET_DMNODE_INFO           _U("EFd057")	/*! 获取需求点数据信息失败*/
#define	UGS_GET_OBJECT_SPATIAL_INFO_FAILED      _U("EFd058")	/*! 获取对象空间信息失败*/
#define	UGS_GET_GEOMETRY_DATA_FAILED            _U("EFd059")	/*! 获取对象空间数据失败*/
#define	UGS_ODBC_GETOBJECTCOUNT_FAILED          _U("EFd060")	/*! 获取对象数失败*/
#define	UGS_ODBC_REFRESHMAXGEOSIZE_FAILED       _U("EFd061")	/*! 获取最大对象的大小失败*/
#define	UGS_FAILED_TO_SETITEMID                 _U("EFd062")	/*! 设置对象ID失败*/
#define	UGS_FAILED_TO_ADJUST_SCALE_COEFFICIENT  _U("EFd063")	/*! 调整比例系数失败*/
#define	UGS_COORDINATE_CONVER_TO_NODE_FAILED    _U("EFd064")	/*! 坐标转化为节点失败*/
#define	UGS_EMPTY_OBJECT_CANNOT_ADD_TO_DATASET  _U("EFd065")	/*! 空对象不能添加到数据集里*/
#define	UGS_ONLY_SUPPORT_SIMPLE_OBJECT          _U("EFd066")	/*! 暂时只支持简单对象*/
#define	UGS_ODBC_GETBOUNDSDIRECTLY_FAILED       _U("EFd067")	/*! 获取外界矩形失败*/
#define	UGS_FAILED_TO_DRAW_TEXT                 _U("EFd068")	/*! 绘制文本对象失败*/
#define	UGS_FAILED_TO_START_EDIT                _U("EFd069")	/*! 开始编辑失败*/
#define	UGS_FAILED_TO_READ_GEOMETRY_D           _U("EFd070")	/*! 读取第%d个几何对象时失败*/
#define	UGS_FAILED_TO_CREATE_GEOMETRY_D         _U("EFd071")	/*! 创建第%d个几何对象时失败*/
#define	UGS_FAILED_TO_READ_ENTITY_INFO          _U("EFd072")	/*! 读取实体信息失败*/
#define	UGS_FAILED_TO_READ_ENTITY_STYLE         _U("EFd073")	/*! 读取实体风格失败*/
#define	UGS_FAILED_TO_READ_ENTITY               _U("EFd074")	/*! 读取实体失败*/
#define	UGS_FAILED_TO_DRAW_LINE_WITH_TWO_POINT  _U("EFd075")	/*! 构造两点线对象失败*/
#define	UGS_NO_SEQUENCE_INFO                    _U("EFd076")	/*! 文件中不存在实体更新显示排序信息*/
#define	UGS_NO_STYLE_TO_IMPORT_HATCH_ENTITY     _U("EFd077")	/*! 忽略风格，则不导入Hatch类型实体*/



// 符号库相关错误
#define	UGS_ICON_IDRESERVED_NOT_ZERO            _U("EGa001")	/*! 读取Icon中字段idReserved不为0*/
#define	UGS_ICON_IDTYPE_NOT_ONE                 _U("EGa002")	/*! 读取Icon中字段idType不为1*/
#define	UGS_ICON_IDCOUNT_LESSTHAN_ZERO          _U("EGa003")	/*! 读取Icon中的idCount小于0*/
#define	UGS_FAILED_TO_GET_THE_SYMBOL            _U("EGa004")	/*! 获取指定符号失败*/
#define	UGS_READ_ICON_FAILED                    _U("EGa005")	/*! 读取Icon数据失败*/
#define	UGS_ICON_INFO_IS_NULL                   _U("EGa006")	/*! 读取Icon信息数据为空*/
#define	UGS_READ_ICON_STROKE_FAILED             _U("EGa007")	/*! 读取Icon笔划失败*/
#define	UGS_ICON_BYTE_IS_NULL                   _U("EGa008")	/*! 读取Icon比特数据为空*/
#define	UGS_READ_POINT_SYMLIB_FAILED_FOR_MARKER_ERROR _U("EGa009")	/*! 点符号库读取时标志有错，读取失败*/
#define	UGS_READ_D_SYMBOL_FAILED                _U("EGa010")	/*! 第%d个符号读取失败*/
#define	UGS_FAILED_TO_GET_EXTENT_SYMBOL_INDEX   _U("EGa011")	/*! 获取扩展符号失败*/
#define	UGS_SAVE_ICON_FAILED                    _U("EGa012")	/*! 保存Icon数据失败*/
#define	UGS_SAVE_ICON_IS_NULL                   _U("EGa013")	/*! 保存Icon数据为空*/
#define	UGS_SAVE_POINT_STROKE_FAILED            _U("EGa014")	/*! 保存点符号笔划失败*/
#define	UGS_FAILED_TO_SAVE_STROKE               _U("EGa015")	/*! 保存笔划失败*/
#define	UGS_FAILED_TO_READ_POINT_STROKE         _U("EGa016")	/*! 读取点符号笔划失败*/
#define	UGS_POINT_SAVE_D_STROKE_FAILED          _U("EGa017")	/*! 点符号第%d个笔划保存失败*/
#define	UGS_POINT_LIB_D_SYMBOL_SAVE_FAILED      _U("EGa018")	/*! 点符号库中第%d个符号保存失败*/
#define	UGS_FAILED_TO_REMOVE_EXTENT_SYMBOL      _U("EGa019")	/*! 移除扩展符号失败*/
#define	UGS_FAILED_TO_REMOVE_THE_SYMBOL         _U("EGa020")	/*! 移除指定符号失败*/
#define	UGS_REMOVE_APPOINTED_INDEX_AND_DELETE_SYMBOL_FAILED _U("EGa021")	/*! 移除指定索引ID并删除符号的操作失败*/
#define	UGS_REMOVE_APPOINTED_ID_SYMBOL_FAILED   _U("EGa022")	/*! 移除指定ID的符号失败*/
#define	UGS_FAILED_TO_READ_POINT_SYMBOL         _U("EGa023")	/*! 点符号读取失败*/
#define	UGS_FAILED_TO_SAVE_POINT_SYMBOL         _U("EGa024")	/*! 点符号保存失败*/
#define	UGS_FAILED_TO_READ_POINT_SYMBOLLIB      _U("EGa025")	/*! 点符号库保存失败*/
#define	UGS_FAILED_TO_SEARCH_SYMBOL_NAME        _U("EGa026")	/*! 查找符号名称失败*/
#define	UGS_CANNOT_FIND_EXTERIOR_SYMBOL         _U("EGa027")	/*! 找不到外部符号*/
#define	UGS_CANNOT_FIND_OPPOSITE_STROKE         _U("EGa028")	/*! 找不到对应的笔划类型*/
#define	UGS_NOT_FIND_POINT_STROKE_OPPOSITE_TYPE _U("EGa029")	/*! 找不到点符号笔划的对应的类型*/
#define	UGS_CANNOT_FIND_SYMBOL_WITH_OPPOSITE_INDEX _U("EGa030")	/*! 找不到对应索引的符号*/
#define	UGS_NOT_FIND_SYMBOL_WITH_THE_NAME       _U("EGa031")	/*! 找不到对应名称的符号*/
#define	UGS_SYMBOL_FOUND_IN_SYMLIB_IS_NULL      _U("EGa032")	/*! 符号库中所找到的符号为空*/
#define	UGS_ROMANCE_POINT_SYMBOL_NOT_FIND_OPPOSITE_SYMBOL_TYPE _U("EGa033")	/*! 渲染点符号时没有找到对应的符号类型*/
#define	UGS_FAILED_TO_SET_SYMBOL_NAME           _U("EGa034")	/*! 设置符号名称失败*/
#define	UGS_ICON_IS_NULL                        _U("EGa035")	/*! Icon数据为空*/
#define	UGS_MOVE_FROM_TO_SELFGROUP_FAILED       _U("EGa036")	/*! 在符号库中移动符号失败*/
#define	UGS_CURRENT_GROUP_EXIST_SYMBOL_WITH_THIS_ID _U("EGa037")	/*! 指定ID的符号在当前组中存在*/
#define	UGS_APPOINT_ID_NOT_EXIST_IN_SYMLIB      _U("EGa038")	/*! 指定ID符号在符号库中不存在*/
#define	UGS_CONSTRUCT_ARC_POINT_POINTER_IS_NULL _U("EGa039")	/*! 构建弧段点指针为空*/
#define	UGS_TEXT_IS_NULL_WHEN_CONSTRUCT_POINT_STROKE _U("EGa040")	/*! 点笔划构建时文本为空*/
#define	UGS_IN_SELFGROUP_AND_SUBGROUP_THIS_ID_NOT_EXIST _U("EGa041")	/*! 在本组及其子组中不存在此ID*/
#define	UGS_NOT_EXIST_NEED_MOVE_SYMBOL_ID       _U("EGa042")	/*! 不存在此时要所要移动符号的ID*/
#define	UGS_SYMBOL_LIB_NOT_FIND_OPPOSITE_NAME_SUBGROUP _U("EGa043")	/*! 符号库没有找到对应名字的子组*/
#define	UGS_CANNOT_FIND_THE_OPPOSITE_NAME_GROUP _U("EGa044")	/*! 在本组及其子组下面没有找到对应名称的组*/
#define	UGS_INVALID_CHILIDGROUP_NAME            _U("EGa045")	/*! 创建子组失败*/
#define	UGS_FAILED_TO_CREATE_CHILIDGROUP        _U("EGa046")	/*! 子组名称已存在*/
#define	UGS_SET_ID_FAILED                       _U("EGa047")	/*! 设置符号的ID失败*/
#define	UGS_SET_ID_REPEAT                       _U("EGa048")	/*! 设置的新符号ID已存在*/
#define	UGS_SYMBOL_INVALID_SYM                  _U("EGa049")	/*! 非法符号*/
#define	UGS_SYMBOL_INVALID_STROKE               _U("EGa050")	/*! 非法符号笔划*/
#define	UGS_NO_TOKEN_INFO                       _U("EGa051")	/*! 没有Token信息*/

// 线型库相关错误，包括子线
#define	UGS_FAILED_TO_CALCULATE_GRADIENT_LINE   _U("EGb001")	/*! 计算渐变线失败*/
#define	UGS_READ_LINE_SYMBOL_EXTEND_FAILED      _U("EGb002")	/*! 读取扩展线型符号失败*/
#define	UGS_FAILED_TO_DRAW_EXTENTLINE           _U("EGb003")	/*! 绘制扩展线型失败*/
#define	UGS_FAILED_TO_SAVE_EXTEND_SYMBOL        _U("EGb004")	/*! 保存扩展线型符号失败*/
#define	UGS_FAILED_TO_SAVE_SYMBOLLINE           _U("EGb005")	/*! 线型符号保存失败*/
#define	UGS_SOLID_PART_IS_ZERO                  _U("EGb006")	/*! 线型的实部为零*/
#define	UGS_READ_SUBLINE_SYMBOL_FAILED          _U("EGb007")	/*! 子线读取失败*/
#define	UGS_LINESYMBOL_FAILED_TO_MOVE_SUBLINE   _U("EGb008")	/*! 移动子线失败*/
#define	UGS_LINESYMBOL_FAILED_TO_REMOVE_SUBLINE _U("EGb009")	/*! 移除子线失败*/
#define	UGS_LINESYMBOL_FAILED_TO_MOVEUP         _U("EGb010")	/*! 将子线上移失败*/
#define	UGS_LINESYMBOL_FAILED_TO_MOVEBOTTOM     _U("EGb011")	/*! 将子线移到底部失败*/
#define	UGS_LINESYMBOL_FAILED_TO_MOVETOP        _U("EGb012")	/*! 将子线移动到顶部失败*/
#define	UGS_SAVE_D_SUBLINE_FAILED               _U("EGb013")	/*! 第%d个子线保存失败*/
#define	UGS_SAVE_SUBLINE_FAILED                 _U("EGb014")	/*! 子线数据保存失败*/
#define	UGS_FAILED_TO_REMOVE_THE_SUBGROUP       _U("EGb015")	/*! 移除指定索引子组失败*/
#define	UGS_FAILED_TO_READ_LINE_SYMBOL          _U("EGb016")	/*! 读取线型符号失败*/
#define	UGS_FAILED_TO_DRAW_LINE_SYMBOL          _U("EGb017")	/*! 读取线型符号失败*/

// 填充库相关错误，包括填充位图、颜色表等
#define	UGS_BIT_DATA_INVLAID                    _U("EGc001")	/*! 位图数据不合法*/
#define	UGS_BITMAP_BIT_IS_NULL                  _U("EGc002")	/*! 位图比特数据为空*/
#define	UGS_BIT_IS_NULL                         _U("EGc003")	/*! 位图数据为空*/
#define	UGS_FILLSYMBOL_IS_NULL                  _U("EGc004")	/*! 填充位图数据为空*/
#define	UGS_BYTE_STREAM_INFO_IS_NULL            _U("EGc005")	/*! 位图字节流信息为空*/
#define	UGS_FAILED_TO_GET_BITMAP_BYTE_COUNT     _U("EGc006")	/*! 获取保存位图的字节数失败*/
#define	UGS_BITMAP_FAILED_TO_IMPORT             _U("EGc007")	/*! 导入位图数据失败*/
#define	UGS_BITMAP_FAILED_TO_DRAW               _U("EGc008")	/*! 绘制位图失败*/
#define	UGS_BITMAP_FAILED_TO_SAVE               _U("EGc009")	/*! 保存位图数据失败*/
#define	UGS_FILLSYM_FAILED_TO_SAVE_BIT          _U("EGc010")	/*! 填充符号保存位图数据失败*/
#define	UGS_BITMAP_FAILED_TO_READ               _U("EGc011")	/*! 读取位图数据失败*/
#define	UGS_READ_BIT_INFO_ERROR                 _U("EGc012")	/*! 读取位图信息不正确*/
#define	UGS_FILLSYMBOL_FAILED_TO_READ_BIT_INFO  _U("EGc013")	/*! 填充符号读取位图信息失败*/
#define	UGS_READ_BIT_STROKE_FAILED              _U("EGc014")	/*! 读取位图笔划时失败*/
#define	UGS_READ_BIT_DIB_DATA_FAILED            _U("EGc015")	/*! 读取位图的数据块（DIB）失败*/
#define	UGS_READ_BIT_DATA_POINTER_IS_NULL       _U("EGc016")	/*! 读取位图数据指针为空*/
#define	UGS_BITMAP_FAILED_TO_GET_BIT_SIZE       _U("EGc017")	/*! 获取位图大小失败*/
#define	UGS_FAILED_TO_READ_SUBFILLSYM_POINT     _U("EGc018")	/*! 读取子填充符号的点符号失败*/
#define	UGS_FAILED_TO_READ_FILLSYMBOL_POINT     _U("EGc019")	/*! 读取填充符号的点符号失败*/
#define	UGS_BITMAP_FAILED_TO_GET_SUBSYMBOL_BIT_SIZE _U("EGc020")	/*! 获取子符号位图大小失败*/
#define	UGS_READ_SUBRASTER_SYMBOL_FAILED        _U("EGc021")	/*! 读取子栅格符号失败*/
#define	UGS_READ_FILLSYM_SUBPOINT_FAILED        _U("EGc022")	/*! 读取填充符号子点符号失败*/
#define	UGS_FILLLIB_FAILED_TO_READ              _U("EGc023")	/*! 读取填充库失败*/
#define	UGS_READ_FILLSYMBOL_FAILED              _U("EGc024")	/*! 填充库读取填充符号失败*/
#define	UGS_FAILED_TO_SAVE_FILLSYMBOL           _U("EGc025")	/*! 保存填充符号失败*/
#define	UGS_FILLLIB_ADD_FAILED                  _U("EGc026")	/*! 填充库添加填充符号失败*/
#define	UGS_FILLLIB_FAILED_TO_APPEND_INFO       _U("EGc027")	/*! 填充库中追加信息失败*/
#define	UGS_TEMPORARY_FILLLIB_APPEND_FAILED     _U("EGc028")	/*! 临时填充库追加失败*/
#define	UGS_FILLSYMBOL_CANNOT_FIND_OPPOSITE_POINT_INFO _U("EGc029")	/*! 填充符号找不到对应的点符号信息*/
#define	UGS_FILLSYMBOL_REMOVE_SUBLAYER_FAILED   _U("EGc030")	/*! 填充符号移除子层失败*/
#define	UGS_UGIMAGE_IS_NULL                     _U("EGc031")	/*! UGImage为空*/
#define	UGS_CREATE_FORMAT_D_UGRGN_FAILED        _U("EGc032")	/*! 创建类型为%d的UGRgn失败*/
#define	UGS_CREATE_FROMAT_D_UGFONT_FAILED       _U("EGc033")	/*! 创建类型为%d的字体失败*/
#define	UGS_CREATE_FROMAT_D_UGIMAGE_FAILED      _U("EGc034")	/*! 创建类型为%d的UGImage失败*/
#define	UGS_READ_COLOR_TABLE_FAILED             _U("EGc035")	/*! 读取颜色表数据失败*/
#define	UGS_FILLSYMBOL_FAILED_TO_RENDER         _U("EGc036")	/*! 填充符号渲染失败*/
#define	UGS_FAILED_TO_TRANS                     _U("EGc037")	/*! 半透明填充失败*/
#define	UGS_NOT_SUPPORT_THE_COLOR_SPACE         _U("EGc038")	/*! 不支持此种颜色模式，目前仅支持RGB、RGBA、CMY、CMYK、YIQ、YUV、YCC。*/
#define	UGS_TIFF_NOT_SUPPROT_RGBA               _U("EGc039")	/*! TIFF没有RGBA模式，自动转换成CMYK*/
#define	UGS_READ_FILLSYM_MATERIAL_FAILED        _U("EGc040")	/*! 读取填充符号材质失败*/

// 画布相关错误
#define	UGS_CREATE_MEMGRAPHIC_FAILED            _U("EGd001")	/*! 创建内存画布失败*/
#define	UGS_GET_BACKGRAPHIC_FAILED              _U("EGd002")	/*! 创建背景画布失败*/
#define	UGS_CREATE_TRANSGRAPHIC_FAILED          _U("EGd003")	/*! 创建半透明画布失败*/
#define	UGS_CREATE_IMAGE_FAILED                 _U("EGd004")	/*! 创建Image失败*/
#define	UGS_FILLSYMPARAM_CREATE_IMAGE_FAILED    _U("EGd005")	/*! 绘制参数创建Image失败*/
#define	UGS_TRANSIMAGE_INVALID                  _U("EGd006")	/*! 透明Image指针为空*/
#define	UGS_BACKIMAGE_INVLAID                   _U("EGd007")	/*! 背景Image指针为空*/
#define	UGS_MEMORY_IMAGE_INVALID                _U("EGd008")	/*! 内存画布指针为空*/

// 画笔、画刷相关错误
#define	UGS_CREATE_BRUSH_FAILED                 _U("EGe001")	/*! 创建画刷失败*/
#define	UGS_CREATE_FROMAT_D_UGBRUSH_FAILED      _U("EGe002")	/*! 创建类型为%d的画刷失败*/
#define	UGS_NEEDNOT_CREATE_BRUSH                _U("EGe003")	/*! 不需要创建画刷*/
#define	UGS_CREATE_FROMAT_D_UGPEN_FAILED        _U("EGe004")	/*! 创建类型为%d的画笔失败*/
#define	UGS_CREATING_PEN_SAMEAS_CURRENT_PEN_NEEDNOT_CREATE _U("EGe005")	/*! 创建画笔与当前的相同，不需要再创建*/

// 显示引擎相关错误
#define	UGS_SEARCH_GRAPHICS_D_UGGRAPHICSMANAGER_FAILED _U("EGf001")	/*! 查找Graphics类型为%d的UGGraphicsManager失败*/
#define	UGS_FAILED_TO_CREATE_MEMORY_GRAPHICS    _U("EGf002")	/*! 创建内存显示引擎失败*/
#define	UGS_FAILED_TO_CREATE_MEMORY_ENGINE      _U("EGf003")	/*! 创建内存引擎失败*/
#define	UGS_FAILED_TO_CHECK_GRAPHIC_DYNAMIC_LIB _U("EGf004")	/*! 检查Graphics动态库失败*/
#define	UGS_CREATE_GRAPHICS_FAILED              _U("EGf005")	/*! 创建显示引擎失败*/

// 图层相关错误，包括图层的状态、对图层的相关操作
#define	UGS_CREATE_FORMAT_D_GRAPHICS_FAILED     _U("EGg001")	/*! 创建类型为%d的Graphics失败*/
#define	UGS_LAYER_TYPE_INVLAID                  _U("EGg002")	/*! 图层类型无效：不支持MrSID和ECW图层*/
#define	UGS_LAYER_IS_UNVISIBLE                  _U("EGg003")	/*! 该图层不可见*/
#define	UGS_CURRENT_LAYER_IS_NULL               _U("EGg004")	/*! 当前编辑图层为空*/
#define	UGS_CURRENT_DATASET_IS_NULL             _U("EGg005")	/*! 当前编辑图层对应的数据集为空*/
#define	UGS_LAYER_DATASET_IS_INVALID            _U("EGg006")	/*! 图层对应的数据集不合法*/
#define	UGS_TRACKINGLAYER_FAILED_TO_CREATE_DATASOURCE _U("EGg007")	/*! 图层创建内存数据源失败*/
#define	UGS_LAYER_NEEDED_MOVING_OVERRUN         _U("EGg008")	/*! 需要移动的图层不在范围之内*/
#define	UGS_LAYERS_NOT_FIND_LAYER_WITH_THE_NAME _U("EGg009")	/*! 没有找到指定名称的图层*/
#define	UGS_NOT_FIND_THE_TOPO_LAYER             _U("EGg010")	/*! 没有找到指定的拓扑数据集图层*/
#define	UGS_LAYERS_NOT_FIND_LAYER_WITH_THE_INDEX _U("EGg011")	/*! 没有找到指定索引的图层*/
#define	UGS_TRACKINGLAYER_FAILED_TO_DRAW        _U("EGg012")	/*! 绘制跟踪层失败*/
#define	UGS_TRACKINGLAYER_FAILED_TO_ADD         _U("EGg013")	/*! 跟踪层添加对象失败*/
#define	UGS_TRACKINGLAYER_FAILED_TO_SEARCH_THE_GEO _U("EGg014")	/*! 跟踪层查找对应几何对象失败*/
#define	UGS_TRACKINGLAYER_FAILED_FIND_THE_LABEL_INDEX _U("EGg015")	/*! 跟踪层查找对应标签的索引失败*/
#define	UGS_TRACKINGLAYER_FAILED_TO_DELETE_THE_LABEL_OBJECT _U("EGg016")	/*! 跟踪层删除对应标签的对象失败*/
#define	UGS_LAYERS_NOT_FIND_USEFUL_LAYER_NAME   _U("EGg017")	/*! 没有找到可用的图层名字*/
#define	UGS_ALREADY_FULL_EXTENT                 _U("EGg018")	/*! 已经是全幅显示*/
#define	UGS_IMPORT_HANDLE_IS_OUT_EXTENT         _U("EGg019")	/*! 传入的句柄为%d,不在可移动的句柄范围内*/
#define	UGS_NOT_SPECIFY_ANY_LAYERS              _U("EGg020")	/*! 尚未指定任何图层,请尝试运行SetAllLayers函数。*/
#define	UGS_FAILED_TO_IMPORT_LAYER              _U("EGg021")	/*! 导入图层[%s]失败*/
#define	UGS_NO_VALID_LAYER                      _U("EGg022")	/*! 图层类型无效：没有支持的图层*/
#define	UGS_MAP_IS_NULL                         _U("EGg023")	/*! 地图指针为空*/
#define	UGS_LAYERS_NEED_NOT_MOVE                _U("EGg024")	/*! 索引相同，不需要移动图层*/

// 地图、布局相关操作错误
#define	UGS_MAP_FAILED_TO_SAVE                  _U("EGh001")	/*! 保存地图失败*/
#define	UGS_MAP_FAILED_TO_SAVEAS                _U("EGh002")	/*! 另存地图失败*/
#define	UGS_MAP_FAILED_TO_DRAW                  _U("EGh003")	/*! 绘制地图失败*/
#define	UGS_UGMAPSTORAGE_CREATE_FAILED          _U("EGh004")	/*! 创建地图失败*/
#define	UGS_CANNOT_OPEN_MAP                     _U("EGh005")	/*! 打开地图失败*/
#define	UGS_MAP_FAILED_TO_OUTPUT                _U("EGh006")	/*!  输出地图失败*/
#define	UGS_MAP_FAILED_TO_RENAME                _U("EGh007")	/*! 地图重命名失败*/
#define	UGS_MAP_FAILED_TO_CLONE                 _U("EGh008")	/*! 地图克隆失败*/
#define	UGS_MAP_FAILED_TO_REMOVE                _U("EGh009")	/*! 移除地图失败*/
#define	UGS_MAP_FAILED_TO_ADD                   _U("EGh010")	/*! 添加地图失败*/
#define	UGS_MAP_FAILED_TO_PRINT                 _U("EGh011")	/*! 打印地图失败*/
#define	UGS_MAP_FAILED_TO_PREPARE_BUFFER        _U("EGh012")	/*! 准备地图缓存失败*/
#define	UGS_FAILED_TO_ONSIZE                    _U("EGh013")	/*! 地图窗口改变大小失败*/
#define	UGS_FAILED_TO_CHECKMARGINPANMODE        _U("EGh014")	/*! 地图撞墙漫游失败*/
#define	UGS_MAP_IS_EXIST                        _U("EGh015")	/*! 名字为%s的地图已存在*/
#define	UGS_FAILED_TO_SET_EDITING_ENVIRONMENT   _U("EGh016")	/*! 地图设置编辑环境失败*/
#define	UGS_MAPWND_DONOT_LINK_WORKSPACE         _U("EGh017")	/*! 地图模拟窗口没有关联工作空间*/
#define	UGS_LAYOUT_LOAD_FAILED                  _U("EGh018")	/*! 导入布局失败*/
#define	UGS_LAYOUT_SAVE_FAILED                  _U("EGh019")	/*! 保存布局失败*/
#define	UGS_UGLAYOUTSTORAGE_CREATE_FAILED       _U("EGh020")	/*! 创建布局失败*/
#define	UGS_LAYOUT_FAILED_TO_CLONE              _U("EGh021")	/*! 克隆布局失败*/
#define	UGS_LAYOUT_FAILED_TO_REMOVE             _U("EGh022")	/*! 移除布局失败*/
#define	UGS_LAYOUT_FAILED_TO_RENAME             _U("EGh023")	/*! 布局重命名失败*/
#define	UGS_LAYOUT_FAILED_TO_ADD                _U("EGh024")	/*! 添加布局失败*/
#define	UGS_LAYOUT_IS_EXIST                     _U("EGh025")	/*! 名字为%s的布局已存在*/
#define	UGS_GET_INDEX_LAYOUT_FAILED_D           _U("EGh026")	/*! 获取索引为%d的布局失败*/
#define	UGS_UGSCENESTORAGE_GET_INDEX_FAILED_D   _U("EGh027")	/*! 获取索引为%d的三维场景失败*/
#define	UGS_UGSCENESTORAGE_NAME_NOT_EXIST       _U("EGh028")	/*! 名字为%s的三维场景不存在*/
#define	UGS_UGSCENESTORAGE_NAME_EXIST           _U("EGh029")	/*! 名字为%s的三维场景已存在*/
#define	UGS_SCENE_FAILED_TO_CLONE               _U("EGh030")	/*! 克隆三维场景失败*/
#define	UGS_SCENE_FAILED_TO_REMOVE              _U("EGh031")	/*! 移除三维场景失败*/
#define	UGS_UGSCENESTORAGE_CREATE_FAILED        _U("EGh032")	/*! 创建三维场景失败*/
#define	UGS_MAP_LOAD_FAILED                     _U("EGh033")	/*! 导入地图失败*/
#define	UGS_MAP_GETAT_FAILED                    _U("EGh034")	/*! 获取地图失败*/
#define	UGS_LAYOUT_FAILED_TO_SETMAPHOLD         _U("EGh035")	/*! 锁定地图失败，已经有地图被锁定，请先取消另一个地图的锁定*/
#define	UGS_LAYOUT_GETGEOPAPER                  _U("EGh036")	/*! 布局获取的纸张对象为空*/
#define	UGS_LAYOUT_HITGEO_IS_PAPER              _U("EGh037")	/*! 选中的对象时纸张对象*/
#define	UGS_RESOLUTION_IS_TOO_HIGH              _U("EGh038")	/*! 输出地图分辨率太大*/
#define	UGS_LAYOUT_GRID_IS_TOO_MUCH             _U("EGh039")	/*! 布局网格太密*/
#define	UGS_LAYOUT_FAILED_TO_DRAW               _U("EGh040")	/*! 绘制布局失败*/
#define	UGS_LAYOUT_GEOPAPER_IS_NULL             _U("EGh041")	/*! 纸张对象为空*/
#define	UGS_LAYOUT_INVALID_GEOPAPER_TYPE        _U("EGh042")	/*! 纸张对象的类型错误*/
#define	UGS_LAYOUT_RULERFONT                    _U("EGh043")	/*! 宋体*/
#define	UGS_MAP_GRID_IS_TOO_MUCH                _U("EGh044")	/*! 地图网格太密*/

// 专题图相关错误，包括保存专题图信息的XML文件等
#define	UGS_FAILED_TO_DRAW_THEMEDOTDENSITY      _U("EGi001")	/*! 绘制点密度专题图失败*/
#define	UGS_FAILED_TO_DRAW_THEMEGRAPH           _U("EGi002")	/*! 绘制统计专题图失败*/
#define	UGS_FAILED_TO_DRAW_ROSE3DGRAPH          _U("EGi003")	/*! 绘制3D玫瑰图失败*/
#define	UGS_FAILED_TO_DRAW_THEMESTYLE           _U("EGi004")	/*! 绘制风格专题图失败*/
#define	UGS_GRAPH_FAILED_TO_HITTEST             _U("EGi005")	/*! 统计专题图鼠标单击响应失败*/
#define	UGS_LABEL_FAILED_TO_HITTEST             _U("EGi006")	/*! 标签专题图鼠标单击响应失败*/
#define	UGS_THEMEGRAPH_FAILED_TO_CAL_FEILD_EXTREMUM _U("EGi007")	/*! 统计专题图计算字段极值失败*/
#define	UGS_THEMERANGE_FAILED_TO_CAL_FEILD_EXTREMUM _U("EGi008")	/*! 范围专题图计算字段极值失败*/
#define	UGS_THEMELABEL_FAILED_TO_CAL_FEILD_EXTREMUM _U("EGi009")	/*! 标签专题图计算字段极值失败*/
#define	UGS_THEMEGRAPH_FAILED_TO_DEFINE_DEFAULT_STYLE _U("EGi010")	/*! 统计专题图设置默认风格失败*/
#define	UGS_THEMERANGE_FAILED_TO_DEFINE_DEFAULT_STYLE _U("EGi011")	/*! 范围专题图设置默认风格失败*/
#define	UGS_THEMEGRAPH_FAILED_TO_REMOVE         _U("EGi012")	/*! 统计专题图移除失败*/
#define	UGS_THEMEUNIQUE_FAILED_TO_REMOVE        _U("EGi013")	/*! 单值专题图移除失败*/
#define	UGS_THEMEDOTDENSITY_FAILED_TO_CONVERT_TO_DATASET _U("EGi014")	/*! 点密度专题图转为数据集失败*/
#define	UGS_THEMESTYLE_FAILED_TO_CONVERT_TO_DATASET _U("EGi015")	/*! 风格专题图转为数据集失败*/
#define	UGS_THEMEGRAPH_FAILED_TO_CONVERT_TO_GEOMETRY _U("EGi016")	/*! 统计专题图转为几何对象失败*/
#define	UGS_THEMEDOTDENSITY_FAILED_TO_CONVERT_TO_GEOMETRY _U("EGi017")	/*! 点密度专题图转为几何对象失败*/
#define	UGS_THEMELABEL_FAILED_TO_CONVERT_TO_GEOMETRY _U("EGi018")	/*! 标签专题图转为几何对象失败*/
#define	UGS_THEMEUNIQUE_FAILED_TO_SWAP          _U("EGi041")	/*! 单值专题图交换失败*/
#define	UGS_THEMEGRAPH_FAILED_TO_SWAP           _U("EGi042")	/*! 统计专题图交换失败*/
#define	UGS_THEMEGRIDRUNIQUE_FAILED_TO_SWAP_STYLE _U("EGi043")	/*! 栅格单值专题图交换失败*/
#define	UGS_THEMEGRIDRANGE_FAILED_TO_REMOVEAT   _U("EGi044")	/*! 栅格范围专题图移除分段失败*/
#define	UGS_THEMELABEL_FAILED_TO_REMOVEAT       _U("EGi045")	/*! 标签专题图移除分段失败*/
#define	UGS_THEMERANGE_FAILED_TO_REMOVEAT       _U("EGi046")	/*! 范围专题图移除分段失败*/
#define	UGS_THEMES_NOT_FIND_THE_THEME_POINTER   _U("EGi047")	/*! 专题图集合没有找到对应指针的专题图*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMEGRID _U("EGi048")	/*! 专题图集合获取可见Grid专题图失败*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMELABEL _U("EGi049")	/*! 专题图集合获取可见标签专题图失败*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMEDOTDENSITY _U("EGi050")	/*! 专题图集合获取可见点密度专题图失败*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMESYMBOL _U("EGi051")	/*! 专题图集合获取可见符号专题图失败*/
#define	UGS_THEMES_FAILED_TO_GET_VISIBLE_THEMESTYLE _U("EGi052")	/*! 专题图集合获取可见风格专题图失败*/
#define	UGS_THEMES_REMOVE_COUNT_LESSTHAN_ONE    _U("EGi053")	/*! 专题图集合删除个数小于1*/
#define	UGS_THEME_NOT_FOUND_THE_INDEX           _U("EGi054")	/*! 专题图找不到对应值的索引*/
#define	UGS_THEME_FAILED_TO_FINDTEXTSTYLE       _U("EGi055")	/*! 专题图查找风格失败*/
#define	UGS_THEMEUNIQUE_FAILED_TO_INSERT_VALUE  _U("EGi056")	/*! 单值专题图插入值失败*/
#define	UGS_THEMEGRADUATE_INVALID_GRADUATEMODE  _U("EGi057")	/*! 等级符号专题图等级符号分级方式不合法*/
#define	UGS_CAN_NOT_CREATE_RANGE_THEMATIC_MAP_WITH_MORE_THAN_X_RANGES _U("EGi058")	/*! 分段的数目不能超过%d*/
#define	UGS_CANNOT_USE_THEMECUSTOM              _U("EGi059")	/*! 自定义专题图不可用*/
#define	UGS_THEMEGRAPH_FORBID_ADDING_LEADERLINE _U("EGi060")	/*! 统计专题图添加牵引线失败*/
#define	UGS_THEMEDOTDENSITY_DOTFILLRANDOM_BOUNDS_IS_NULL _U("EGi061")	/*! 点密度专题图填充范围为空*/
#define	UGS_THEMELABEL_FAILED_TO_READ_UNIQUE_TEXT_STYLE _U("EGi062")	/*! 标签专题图读取单个文本风格时失败*/
#define	UGS_THEMELABEL_SET_DISPLAY_FORMAT_EXCEPTION _U("EGi063")	/*! 标签专题图设置显示格式时出现异常*/
#define	UGS_THEMEGRIDRANGE_INVALID_SEGMENT      _U("EGi064")	/*! 栅格范围专题图设置分段时分段个数无效*/
#define	UGS_THEMEUNIQUE_NOT_FIND_THE_VALUE_CAPTION _U("EGi065")	/*! 单值专题图没有找到对应值的标题*/
#define	UGS_FAILED_TO_MAKEALONGLINETEXT         _U("EGi066")	/*! 标签专题图绘制沿线标注失败*/
#define	UGS_SLMSG_THEME_UNIQUE_KEYTYPE_INVALID  _U("EGi067")	/*! 非法的单值专题图键值*/
#define	UGS_SLMSG_THEME_RANGE_KEYTYPE_INVALID   _U("EGi068")	/*! 非法的范围分段专题图键值*/
#define	UGS_FAILED_TO_FINDSTYLE                 _U("EGi069")	/*! 单值专题图查找对应风格失败*/
#define	UGS_THEMEGRADUATE_VALUE_IS_ZERO         _U("EGi070")	/*! 等级符号专题图的段值必须大于0*/
#define	UGS_FAILED_TO_DRAW_THEMELABEL           _U("EGi071")	/*! 绘制标签专题图失败*/
#define	UGS_THEMEBASE_FAILED_TO_XML             _U("EGi072")	/*! 专题图保存为xml失败*/
#define	UGS_THEMEGRADUATEDSYMBOL_UNSUPPORTED_CAD _U("EGi073")	/*! 等级符号专题图不支持CAD数据集*/
#define	UGS_THEMELABEL_TEXT_STYLE_COUNT_IS_ZERO _U("EGi074")	/*! 标签专题图文本多样化的风格个数为零*/
#define	UGS_AVAILABLE_VALUE_COUNT_IS_ZERO       _U("EGi075")	/*! 单值专题图有效值个数为零*/

// 地图要素（包括图幅图框、图例、指北针、比例尺等）相关错误
#define	UGS_FAILED_TO_SET_SCALE                 _U("EGj001")	/*! 设置比例尺失败*/

// 资源（包括工作空间的资源库、基本配置文件，字体、投影等xml文件）相关错误
#define	UGS_FAILED_TO_IMPORT_RESOURCES          _U("EGk001")	/*! 导入资源文件失败*/



// 投影转换相关错误
#define	UGS_CANNOT_FIND_PRJCONFIG_XML           _U("EHa001")	/*! 找不到投影配置文件*/
#define	UGS_ORIGINAL_COORDINATES_SYSTEM_IS_NULL _U("EHa002")	/*! 源坐标系为空*/
#define	UGS_COORDINATE_REFERENCE_IS_EMPTY       _U("EHa003")	/*! 坐标参考系为空*/
#define	UGS_CANNOT_CONVERT_UGPJTYPE             _U("EHa004")	/*! 无法进行空间参考变换*/
#define	UGS_ORGINAL_COORDINATES_NOT_PROJECTION_AND_TARGET_COORDINATES_IS_NULL _U("EHa005")	/*! 源坐标系不是投影坐标系，目标坐标系为空*/
#define	UGS_ORGINAL_OR_TARGET_COORDINATES_IS_PLANE_COORDINATE _U("EHa006")	/*! 源坐标系或目标坐标系有一个是平面坐标系*/
#define	UGS_CANNOT_CONVERT_UGPJTYPE_PLANAR_COORD_SYSTEM_TO_EARTH_COORD_SYSTEM _U("EHa007")	/*! 无法进行空间参考变换：-->地理坐标系或者投影坐标系*/
#define	UGS_LONGITUDE_LATITUDE_SAME_COORDINATE_SYSTEM _U("EHa008")	/*! 经纬度 ==> 经纬度,坐标系相同*/
#define	UGS_PROJECTION_SAME_COORDINATE_SYSTEM   _U("EHa009")	/*! 投影==>投影，坐标系相同*/
#define	UGS_PJCONVERT_POINTER_IS_NULL_OR_DATASOURCE_COORDINATES_IS_PLANE_COORDINATES _U("EHa010")	/*! 坐标系转换计算器指针为空，或数据源为平面坐标系。*/
#define	UGS_PJCONVERT_TARGET_PJSYSTEM_IS_PLANE_COORDINATES _U("EHa011")	/*! 坐标系转换计算器目标投影坐标系为平面坐标系。*/
#define	UGS_PJCOORDSYS_POINTER_IS_NULL_OR_DATASOURCE_COORDSYS_IS_PLANE_COORDSYS _U("EHa012")	/*! 投影坐标系定义指针为空,或数据源为投影坐标系*/
#define	UGS_PJCOORDSYS_COORDSYS_NOT_LONGITUDE_LATITUDE _U("EHa013")	/*! 投影坐标系定义的空间坐标系不是经纬度坐标系。*/
#define	UGS_PJCOORDSYS_COORDSYS_NOT_PJCOORDSYS  _U("EHa014")	/*! 投影坐标系定义的空间坐标系不是投影坐标系。*/
#define	UGS_SPATIALREFTYPE_IS_INVALID           _U("EHa015")	/*! 投影类型不合法*/
#define	UGS_PREFTRANSLATOR_IS_NULL              _U("EHa016")	/*! 投影指针为空*/
#define	UGS_KML_MUSTBE_WGS1984                  _U("EHa017")	/*! KML文件坐标系必须是WGS_1984*/
#define	UGS_FME_CREATE_SESSION_FAILED           _U("EHa018")	/*! FME创建会话管理失败*/
#define	UGS_FME_CLOSE_SESSION_FAILED            _U("EHa019")	/*! FME关闭会话管理失败*/
#define	UGS_FME_CREATE_READER_FAILED            _U("EHa020")	/*! FME创建Reader失败*/
#define	UGS_FME_CREATE_WRITER_FAILED            _U("EHa021")	/*! FME创建Writer失败*/
#define	UGS_FME_OPEN_READER_FAILED				_U("EHa022")	/*! FME打开Reader失败*/
#define	UGS_FME_OPEN_WRITER_FAILED			    _U("EHa023")	/*! FME打开Writer失败*/
#define	UGS_FME_CLOSE_READER_FAILED				_U("EHa024")	/*! FME关闭Reader失败*/
#define	UGS_FME_CLOSE_WRITER_FAILED			    _U("EHa025")	/*! FME关闭Writer失败*/
#define	UGS_FME_READED_SCHEMA_FEATURE_FAILED	_U("EHa026")	/*! 读取概要要素失败*/
#define	UGS_FME_READED_VERITY_FEATURE_FAILED	_U("EHa027")	/*! 读取真实要素失败*/
#define	UGS_FME_REGISTER_OEM_FAILED             _U("EHa028")	/*! FME注册OEM失败*/



// 像素
#define	UGS_UNSUPPORT_PIXELFORMAT               _U("EIa001")	/*! 不支持的像素格式*/
#define	UGS_CANNOT_APPEND_FOR_PIXEL_IS_DIFFERENT _U("EIa002")	/*! 像素格式不一致，不能追加*/
#define	UGS_FAILED_TO_CREATE_RASTER_FOR_INVALID_PIXEL_FORMAT _U("EIa003")	/*! 不支持的像素格式,创建栅格数据集失败*/
#define	UGS_INVALID_PIXELFORMAT                 _U("EIa004")	/*! 像素格式非法*/
#define	UGS_PIXELFORMAT_LESS_THAN_SIXTEEN       _U("EIa005")	/*! 像素格式小于16位*/
#define UGS_PIXELFORMAT_CONVERT_TO_8BITS        _U("EIa006")    /*! 像素转换为8位*/
#define UGS_TEMSCLUTTER_NOT_SUPORT_PIXELFORMAT_GREATER_THAN_SIXTEEN _U("EIa007")/*! 电信栅格不支持像素格式大于16位的数据导出*/

// 影像块
#define	UGS_IMAGE_BLOCK_POINTER_IS_NULL         _U("EIb001")	/*! 影像块指针为空*/
#define	UGS_IMAGE_BLOCK_IS_EMPTY                _U("EIb002")	/*! 影像块范围为空*/
#define	UGS_IMAGE_BLOCK_SIZE_IS_ZERO            _U("EIb003")	/*! 影像块尺寸为0*/
#define	UGS_ODBC_RASTER_CACHEBYBLOCK_FAILED     _U("EIb004")	/*! 栅格块缓存失败*/
#define	UGS_ODBC_RASTER_FAVEBLOCK_FAILED        _U("EIb005")	/*! 栅格存储块失败*/
#define	UGS_IMGBLOCK_GET_FAILED                 _U("EIb006")	/*! 获取影像块出错*/
#define	UGS_FAILED_TO_DRAW_IMAGEBLOCK           _U("EIb007")	/*! 绘制影像块失败*/
#define	UGS_FAILED_TO_SET_IMGBLOCK              _U("EIb008")	/*! 设置影像块失败*/
#define	UGS_FAILED_TO_LOAD_BLOCK                _U("EIb009")	/*! 加载影像块失败*/
#define	UGS_FAILED_TO_MAKE_BLOCK_SEQUENCE       _U("EIb010")	/*! 序列化影像块失败*/
#define	UGS_IMAGE_BLOCK_FAILED_TO_RELEASE       _U("EIb011")	/*! 释放影像块失败*/
#define	UGS_FAILED_TO_LOAD_BLOCK_LD             _U("EIb012")	/*! 加载影像块失败：Col=%ld.Row=%ld*/
#define	UGS_FAILED_TO_GET_IMAGE_BLOCK_SIZE      _U("EIb013")	/*! 获取影像块大小失败*/
#define	UGS_FAILED_TO_SAVE_IMAGEBLOCK           _U("EIb014")	/*! 保存影像块失败*/

// 扫描线
#define	UGS_SCANLINE_ROW_OVERRUN                _U("EIc001")	/*! 扫描线行超过数据集边界*/
#define	UGS_SCANLINE_BEGINING_COLUMN_OVERRUN    _U("EIc002")	/*! 扫描线开始列超过数据集边界*/
#define	UGS_ECW_NOT_SUPPORT_TO_GET_SCANLINE     _U("EIc003")	/*! ECW数据集不支持得到扫描线*/

// 影像压缩，包括金字塔、编码压缩等
#define	UGS_ODBC_BUILDPYRAMID_FAILED            _U("EId001")	/*! 创建影像金字塔失败*/
#define	UGS_ODBCDATASETRASTER_TIER_ISAVAILABLEDATASETNAME_FAILED _U("EId002")	/*! 金字塔数据集名称非法*/
#define	UGS_DONOT_HAVE_PYRAMIDS                 _U("EId003")	/*! 没有金字塔*/
#define	UGS_HAS_BULIDPYRAMID                    _U("EId004")	/*! 已经建立金字塔*/
#define	UGS_ODBC_REMOVEPYRAMIDS_FAILED          _U("EId005")	/*! 删除金字塔失败*/
#define	UGS_FAILED_TO_DCTCODE_FOR_BLOCK         _U("EId006")	/*! 对影像块进行DCT编码失败*/
#define	UGS_DATA_SIZE_IS_TOO_SMALL_TO_COMPRESS  _U("EId007")	/*! 数据量太小，压缩不进行*/
#define	UGS_CANNOT_COMPRESS_FOR_BLOCK_SIZE_IS_OVERRUN _U("EId008")	/*! 块的尺寸不合要求，无法进行SGL编码*/
#define	UGS_FAILED_TO_CODE                      _U("EId009")	/*! 编码失败*/
#define	UGS_UNSUPPORT_CODE_TYPE                 _U("EId010")	/*! 不支持此种编码类型*/
#define	UGS_FAILED_TO_COMPRESS                  _U("EId011")	/*! 数据压缩失败*/
#define	UGS_UNSUPPORT_REMOVEPYRAMIDS            _U("EId012")	/*! 只读文件不支持删除金字塔操作*/

// 栅格数据集操作相关错误，包括打开、关闭、删除、追加等
#define	UGS_FIRST_LEVEL_GIRD_MUST_MORETHAN_ZERO _U("EIe001")	/*! 第一层网格大小必须大于0*/
#define	UGS_CANNOT_SUPPORT_APPEND_DIFFERNT_RESOLUTION_IAMGE _U("EIe002")	/*! 不支持不同分辨率的影像数据集追加*/
#define	UGS_FAILED_TO_FILETER_OBJECT_FROM_THE_GIRD _U("EIe003")	/*! 从相关格子中过滤对象失败*/
#define	UGS_RASTER_FAILED_TO_CALCULATE_EXTREMUM_BY_REGION _U("EIe004")	/*! 栅格计算极值失败*/
#define	UGS_FAILED_TO_CREATE_RASTER             _U("EIe005")	/*! 创建栅格数据集失败*/
#define	UGS_FAILED_TO_CREATE_RASTER_DATASET     _U("EIe006")	/*! 创建栅格数据集：%s失败*/
#define	UGS_ODBC_RASTER_CLOSE_FAILED            _U("EIe007")	/*! 关闭栅格数据集失败*/
#define	UGS_ODBC_RASTER_SAVEINFO_FAILED         _U("EIe008")	/*! 存储栅格信息失败*/
#define	UGS_FAILED_TO_DRAW_RASTER               _U("EIe009")	/*! 绘制栅格数据集失败*/
#define	UGS_FAILED_TO_TRANSFER_IMAGE_TO_RASTER  _U("EIe010")	/*! 从影像到栅格的数据转换失败*/
#define	UGS_ECW_AND_MRSID_NOT_SUPPORT_BULIDPYRAMID _U("EIe011")	/*! 不支持对ECW和MrSID数据建立金字塔*/
#define	UGS_RASTER_FAILED_TO_REGISTER_OPTION    _U("EIe012")	/*! 栅格数据集注册选项信息失败*/
#define	UGS_RASTER_FAILED_TO_UNREGISTER_OPTION  _U("EIe013")	/*! 栅格数据集注销选项信息失败*/
#define	UGS_FAILED_TO_ADD_BAND                  _U("EIe014")	/*! 添加波段失败*/
#define	UGS_FAILED_TO_DELETE_BAND               _U("EIe015")	/*! 删除波段失败*/
#define	UGS_FAILED_TO_REFRESHOPTION             _U("EIe016")	/*! 刷新选项信息失败*/
#define	UGS_FAILED_TO_APPEND_FOR_NO_INTERSECT   _U("EIe017")	/*! 源数据集与目标数据集范围不相交，无法追加*/
#define	UGS_FAILED_TO_FIND_BAND_D               _U("EIe018")	/*! 找不到波段：%d*/
#define	UGS_FAILED_TO_CREATE_RASTER_FILE        _U("EIe019")	/*! 创建栅格数据文件失败*/
#define	UGS_FAILED_TO_CREATE_VECTOR_FILE        _U("EIe020")	/*! 创建矢量数据文件失败*/
#define	UGS_FAILED_TO_GETBANDINFO               _U("EIe021")	/*! 获取波段信息失败*/
#define	UGS_ONLY_SUPPORT_SINGLE_BAND            _U("EIe022")	/*! 仅支持单波段图片输出*/
#define	UGS_NOT_RASTER                          _U("EIe023")	/*! 试图用非栅格数据进行栅格运算*/
#define	UGS_ODBC_GRID_APPEND_VECTOR_UNLAWFUL    _U("EIe024")	/*! 不能将栅格数据追加到矢量数据集中！*/
#define	UGS_ODBC_OVERRUN_APPEND_FAILED          _U("EIe025")	/*! 导入数据范围超过目标数据集范围，不能执行追加操作！*/
#define	UGS_ODBC_PIXELFORMAT_UNSUITED_APPEND_FAILED _U("EIe026")	/*! 导入数据像素格式与目标数据集像素格式不匹配，不能执行追加操作！*/
#define	UGS_CREATESPACE_TO_SCANLINE_FAILED      _U("EIe027")	/*! 为scanline准备空间失败！*/
#define	UGS_POINTER_OF_FILEPARSER_IS_NULL       _U("EIe028")	/*! Fileparser指针为空！*/
#define	UGS_CANNOT_SUPPORT_RESOLUTION           _U("EIe029")	/*! 此格式不支持的分辨率*/
#define	UGS_CANNOT_SUPPORT_COMPOSITE            _U("EIe030")	/*! 此数据不支持合成波段模式*/
#define UGS_RASTOR_FILE_INVALID                 _U("EIe031")    /*! 影像地理坐标参考文件非法*/

// 栅格数据集集合相关错误
#define UGS_RASTER_TYPE_NOT_MATCH               _U("EIf001")    /*! 数据集类型与集合不匹配，不能加入集合*/
#define UGS_RASTER_PROJECT_NOT_EQUAL            _U("EIf002")    /*! 投影与集合的不一致，添加失败*/
#define UGS_RASTER_BANDCOUNT_NOT_EQUAL			_U("EIf003")    /*! 数据集波段数与集合不一致，不能加入集合*/
#define UGS_OPEN_FILE_FAIL_BY_IMGPlUGINS		_U("EIf004")    /*! 影像插件打开影像文件失败*/
#define UGS_GET_SUBDATASET_FAIL					_U("EIf005")    /*! 获取子数据集失败*/
#define UGS_NOT_FIND_SUBDATASET					_U("EIf006")    /*! 指定的别名在数据集合中未找到*/
#define UGS_ADD_SUBDATASET_FAIL					_U("EIf007")    /*! 往栅格数据集集合中添加子数据集失败*/
#define UGS_DELETE_SUBDATASET_FAIL				_U("EIf008")    /*! 删除栅格数据集集合中的子数据集失败*/
#define UGS_ALIAS_EMPTY_OR_EXIT					_U("EIf009")    /*! 添加失败，子数据集别名为空或已存在*/
#define UGS_CANNOT_OPEN_SUBDATASET				_U("EIf010")    /*! 无法打开所指定名称的数据集*/
#define UGS_DATASOURCE_NOTSAME_CANNOT_APPEND	_U("EIf011")    /*! 跨数据源的数据集，现在不支持追加*/
#define UGS_ALIAS_NAME_INVALID					_U("EIf012")    /*! 别名不合法*/
#define UGS_ALIAS_NAME_NOT_FIND					_U("EIf013")    /*! 未找到合法的别名*/
#define UGS_SUBDATASET_CANNOT_VIEW				_U("EIf014")    /*! 子数据集[%s]宽或高大于5000，且集合无金字塔，不显示*/

// SuperMap各产品、各版本之间的兼容性错误信息
#define	UGS_INVALID_GML_VERSION                 _U("EJa001")	/*! GML版本信息非法*/
#define	UGS_CANNOT_FIND_THE_VERSION             _U("EJa002")	/*! 找不到对应的版本*/
#define	UGS_NOT_SUPPORT_LOW_VERISON             _U("EJa003")	/*! 不支持低版本*/
#define	UGS_UNKNOWN_SYMBOL_VERSION              _U("EJa004")	/*! 不识别的符号版本*/
#define	UGS_UNKNOWN_WORKSPACE_VERSION           _U("EJa005")	/*! 未知的工作空间版本*/
#define	UGS_WEBENGINE_ONLY_SUPPORT_THIS_WCS_VERSION _U("EJa006")	/*! 网络数据引擎只支持WCS1.0.0版本*/
#define	UGS_WEBENGINE_ONLY_SUPPORT_THIS_WFS_VERSION _U("EJa007")	/*! 网络数据引擎只支持WFS1.0.0版本*/
#define	UGS_WEB_ENGINE_NOT_SUPPORT_THIS_WFS_VERSION _U("EJa008")	/*! 网络数据引擎不支持该WFS版本*/
#define	UGS_SQLPLUS_DS_OPEN_FAILED_FIVE_POINT_ZERO _U("EJa009")	/*! 打开5.0版本数据源失败*/
#define	UGS_SQLPLUS_DS_OPEN_FAILED_FIVE_POINT_THREE _U("EJa010")	/*! 打开5.3版本数据源失败*/
#define	UGS_FAILED_TO_OPEN_DATA_OF_FIFTY_AND_AGO _U("EJa011")	/*! 打开50以前版本的数据失败*/
#define	UGS_FAILED_TO_OPEN_DATA_OF_FIFTYONE     _U("EJa012")	/*! 打开51版本的数据失败*/
#define	UGS_NOT_SUPPORT_OPEN_LOW_VERSION_DATA   _U("EJa013")	/*! 低版本的数据不支持打开*/
#define	UGS_UNKNOWN_FILE_VERSION                _U("EJa014")	/*! 未知的文件版本*/
#define	UGS_TWO_DATASET_ISNOT_COMPATIBLE        _U("EJa015")	/*! 两个数据集不兼容*/
#define	UGS_LAYOUT_LOW_VERSION                  _U("EJa016")	/*! 布局版本太低，此布局不支持，请更新到UGC60以上版本!*/
#define	UGS_OPEN_REGISTER_BEFORE_FIVE_POINT_ZERO_EDITION_FAILD _U("EJa017")	/*! 打开50以前的注册表失败!*/
#define	UGS_OPEN_REGISTER_SIX_POINT_ZERO_EDITION_FAILD _U("EJa018")	/*! 打开60的注册表失败!*/
#define	UGS_CUSTOM_NONSUPPORT_SERVER_EDITION    _U("EJa019")	/*! 客户端不支持服务器所支持的版本*/
#define	UGS_NO_KEYWORD_IN_URL                   _U("EJa020")	/*! 关键字不存在URL里*/
#define	UGS_NO_SERVICE_TYPE                     _U("EJa021")	/*! 服务类型不存在*/
#define	UGS_SERVER_NONSUPPORT_FORMAT            _U("EJa022")	/*! 服务器不支持此格式*/
#define	UGS_SEARCH_BOUNDS_BEYOND_SERVER_COVERAGE _U("EJa023")	/*! 查询范围不在服务器Coverage可视范围之内*/

// SuperMap U系列产品对设备的兼容
#define	UGS_ODBC_SUPPORT_FUNCTIONS_FAILED       _U("EJb001")	/*! 驱动程序不支持该ODBC函数*/

// 网络连接的相关错误
#define	UGS_REQUEST_ERROR                       _U("EJc001")	/*! 错误请求*/
#define	UGS_FAILD_TO_IMPORT_THE_RESOURCES_ON_SERVER _U("EJc002")	/*! 所请求的服务端资源不存在*/
#define	UGS_INTERNAL_SERVER_ERROR               _U("EJc003")	/*! 服务端内部错误*/
#define	UGS_ACCESS_DENIED                       _U("EJc004")	/*! 访问被拒绝*/
#define	UGS_CAN_NOT_CONNECT_TO_SERVER           _U("EJc005")	/*! 无法连接的服务端*/
#define	UGS_CAN_NOT_REQUEST_BIG_THOUSAND        _U("EJc006")	/*! 查询的瓦片张数超过1000张*/



// 查询条件相关的错误，包括查询记录集、查询游标、查询算子、查询语句、查询选项等的错误
#define	UGS_QUERY_CURSOR_HANDLE_IS_NULL         _U("EKa001")	/*! 查询游标的语句句柄为空*/
#define	UGS_QUERY_OPTION_WRONG                  _U("EKa002")	/*! 查询选项非法*/
#define	UGS_QUERY_IDS_EMPTY                     _U("EKa003")	/*! 查询ID为空*/
#define	UGS_ARRAY_IS_NULL                       _U("EKa004")	/*! 查询的IDS数组为空*/
#define	UGS_SPATIALQUERY_OPTION_ILLEGAL         _U("EKa005")	/*! 空间查询选项非法*/
#define	UGS_QUERY_OPERATER_INVALID              _U("EKa006")	/*! 查询算子不合法*/
#define	UGS_NOT_SUPPORT_THE_QUERY_TYPE          _U("EKa007")	/*! 不支持该查询类型*/
#define	UGS_SPATIALQUERY_GEOMETRY               _U("EKa008")	/*! 不能对非空间数据集进行空间查询*/
#define	UGS_LINKDATA_NOT_SUPPORT_QUERY          _U("EKa009")	/*! 关联数据不支持查询*/
#define	UGS_QUERIED_OBJECT_POINTER_NULL         _U("EKa010")	/*! 查询对象指针为空*/
#define	UGS_QUERY_OBJECT_TYPE_INVALID           _U("EKa011")	/*! 查询对象类型不合法*/
#define	UGS_QUERING_RECORDSET_OBJECTS_COUNT_IS_ZERO _U("EKa012")	/*! 查询记录集对象数为0*/
#define	UGS_QUERY_RECORDSET_POINTER_IS_NULL     _U("EKa013")	/*! 查询记录集指针为空*/
#define	UGS_QUERY_RECORDSET_TYPE_INVALID        _U("EKa014")	/*! 查询记录集类型不合法*/
#define	UGS_QUERY_DATASET_POINTER_IS_NULL       _U("EKa015")	/*! 查询数据集指针为空*/
#define	UGS_QUERIED_RECORDSET_POINTER_NULL      _U("EKa016")	/*! 被查询记录集指针为空*/
#define	UGS_QUERIED_DATASET_POINTER_NULL        _U("EKa017")	/*! 被查询数据集指针为空*/
#define	UGS_QUERIED_RECORDSET_TYPE_INVALID      _U("EKa018")	/*! 被查询记录集类型不合法*/
#define	UGS_QUERIED_RECORDSET_OBJECTS_COUNT_IS_ZERO _U("EKa019")	/*! 被查询记录集对象数为0*/
#define	UGS_ODBC_SQL_EXECUTE_FAILED             _U("EKa020")	/*! 执行SQL语句失败*/
#define	UGS_INVALID_EXPRESSION                  _U("EKa021")	/*! 非法的表达式*/
#define	UGS_FAILED_TO_GET_QUERYDEF              _U("EKa022")	/*! 获取查询条件失败*/
#define	UGS_FAILED_TO_FIND_FIELD_WITH_THE_NAME_S _U("EKa023")	/*! 没有发现同名字段%s*/
#define	UGS_FAILED_TO_QUERY_BY_BOUNDS           _U("EKa024")	/*! Bounds查询失败*/

// 查询结果错误，例如查询失败、查询结果为空
#define	UGS_QUERY_RESULT_IS_NULL                _U("EKb001")	/*! 查询结果为空*/
#define	UGS_QUERY_RECORDSET_IS_NULL             _U("EKb002")	/*! 查询结果记录集指针为空*/
#define	UGS_QUERY_RECORDSET_IS_EMPTY            _U("EKb003")	/*! 查询结果记录集的记录数为0*/
#define	UGS_OBJECTS_IDENTITY_QUERY_FAILED       _U("EKb004")	/*! 对象同一查询失败*/
#define	UGS_FAILED_TO_SEARCH                    _U("EKb005")	/*! 查找失败*/
#define	UGS_TEMPTABLE_FAILED_TO_RELATE_QUERY    _U("EKb006")	/*! 临时表关联查询失败*/
#define	UGS_FAILED_TO_RELATE_QUERY              _U("EKb007")	/*! 关联查询失败*/
#define	UGS_FAILED_TO_QUERY_BY_SUBBOUNDS        _U("EKb008")	/*! 以子边框查询失败*/
#define	UGS_EDITING_RECORDSET_NOT_SUPPORT_STATISTIC_QUERY _U("EKb009")	/*! 可编辑记录集不支持统计查询*/
#define	UGS_FAILED_TO_SEARCH_NETWORK_NODEDT     _U("EKb010")	/*! 查询网络点数据集失败*/
#define	UGS_FAILED_TO_SEARCH_NETWORK_LINEDT     _U("EKb011")	/*! 查询网络线数据集失败*/
#define	UGS_MAP_BREADTH_QUERY_GET_ID_FAILED     _U("EKb012")	/*! 图幅空间查询获取图幅ID失败*/
#define	UGS_FAILED_TO_GET_THE_GRID_CORRELATIVE_WITH_QUERY_OBJECTS _U("EKb013")	/*! 提取与查询对象相关的格子失败*/
#define	UGS_FAILED_TO_QUERY_RECORDSET           _U("EKb014")	/*! 记录集查询失败*/
#define	UGS_FAILED_TO_QUERY_TABLE_STRUCTURE     _U("EKb015")	/*! 查询表的字段结构错误*/



// 记录集位置错误（包括游标错误）
#define	UGS_RECORDSET_POINT_TO_BOF              _U("ELa001")	/*! 记录集游标在开头*/
#define	UGS_RECORDSET_POINT_TO_EOF              _U("ELa002")	/*! 记录集游标在结尾*/
#define	UGS_CURSORTYPE_IS_OPENFORWARD_ONLY      _U("ELa003")	/*! 当前游标处于向前滑动状态*/
#define	UGS_CURSORTYPE_IS_OPENFORWARDONLY       _U("ELa004")	/*! 当前游标处于向前滑动状态*/
#define	UGS_CURSOR_HANDLE_IS_NULL               _U("ELa005")	/*! 游标句柄为空*/
#define	UGS_CURRENT_CURSOR_POS_ILLEGAL          _U("ELa006")	/*! 当前的游标位置非法*/
#define	UGS_CANNOT_MOVE_FORWARD                 _U("ELa007")	/*! 无法向前移动游标*/
#define	UGS_IS_BOF                              _U("ELa008")	/*! 已到记录头*/
#define	UGS_IS_EOF                              _U("ELa009")	/*! 已到记录尾*/
#define	UGS_CURRENT_RECOR_POINT_TO_BOF_OR_EOF   _U("ELa010")	/*! 当前记录指向文件头或者文件尾*/
#define	UGS_OVERRUN_RECORDSET_BOUND             _U("ELa011")	/*! 超出记录集范围*/
#define	UGS_RECORDSET_OUTOF_BOUNDS              _U("ELa012")	/*! 记录集越界*/
#define	UGS_RECORDSET_NOT_OPEN                  _U("ELa013")	/*! 记录集未打开*/
#define	UGS_ODBC_FILL_TABLE_EXTINFO_FAILED      _U("ELa014")	/*! 添加记录失败*/
#define	UGS_RECORDSET_ISNOT_MOVEFIRST           _U("ELa015")	/*! 尚未移动到第一条记录*/
#define	UGS_THE_RECORD_ID_IS_ZERO               _U("ELa016")	/*! 当前记录的ID为0*/
#define	UGS_RECORDSET_INDEX_INVALID             _U("ELa017")	/*! 记录集索引无效*/
#define	UGS_RECORD_AT_THIS_INDEX_NOT_EXIST      _U("ELa018")	/*! 该索引的记录不存在*/
#define	UGS_THE_RECORD_INDEX_OVERRUN            _U("ELa019")	/*! 当前记录索引超过记录数*/
#define	UGS_THE_RECORD_INDEX_ILLEGAL            _U("ELa020")	/*! 当前记录索引非法*/
#define	UGS_RECORD_NOT_EDITABLE                 _U("ELa021")	/*! 该记录处于非编辑模式*/
#define	UGS_RECORD_EDIT_MODE_ILLEGAL            _U("ELa022")	/*! 该记录的编辑模式不合法*/
#define	UGS_INSERTPOS_INVALID                   _U("ELa023")	/*! 得到插入位置非法*/
#define	UGS_POS_IS_INVALID                      _U("ELa024")	/*! 位置非法*/
#define	UGS_FAILED_TO_CREATE_UUID               _U("ELa025")	/*! 创建获取UUID函数失败*/
#define	UGS_CURRENT_CURSOR_REF_NOT_ZERO_AND_NOT_CONNECT_AGAIN _U("ELa026")	/*! 当前游标引用数不为0，不会进行重新连接操作*/

// 数据集类型错误
#define	UGS_DATASET_TYPE_INVLAID                _U("ELb001")	/*! 数据集类型不合法*/
#define	UGS_DATASET_IS_NOT_IMAGE                _U("ELb002")	/*! 数据集类型不是Image(DEM,Grid)*/
#define	UGS_THIS_TYPE_DATASET_NOT_SUPPORT_UNION _U("ELb003")	/*! 此数据集类型不支持合并操作*/
#define	UGS_LAYERS_UNSUPPORT_ADDING_DATASET_AS_ATTRIBUTE _U("ELb004")	/*! 暂不支持属性表数据集到地图窗口中显示*/
#define	UGS_NOT_SUPPORT_THIS_DATASET_TYPE       _U("ELb005")	/*! 不支持的数据集类型*/
#define	UGS_APPENDING_DATASET_TYPE_MISMATCH     _U("ELb006")	/*! 追加的数据集类型不匹配*/
#define	UGS_ONLY_TIN_SUPPORT_THIS_METHOD        _U("ELb007")	/*! 只有Tin数据集支持此方法*/
#define	UGS_CANNOT_ADD_ATTRIBUTE_TO_TOPO        _U("ELb008")	/*! 不支持对纯属性表数据集进行拓扑处理*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY_CANNOT_APPEND_RECORD _U("ELb009")	/*! 不支持向纯属性表中添加几何对象*/
#define	UGS_NOT_SUPPORT_THIS_ORACLE_DATA_TYPE   _U("ELb010")	/*! 不支持的Oracle数据类型*/
#define	UGS_THE_ENGINE_NOT_SUPPORT_CREATE_THS_TYPE_DATASET _U("ELb011")	/*! 此引擎暂时不支持这种数据集的创建*/
#define	UGS_NOT_SUPPORT_THIS_WEBENGINE          _U("ELb012")	/*! 不支持的网络引擎类型*/
#define	UGS_INVALID_DATASET                     _U("ELb013")	/*! 数据集不合法*/
#define	UGS_DATASET_IS_ATTRIBUTE                _U("ELb014")	/*! 数据集类型为属性表数据集*/
#define	UGS_THEMEGRAPH_HITTEST_DATASET_IS_NOT_RASTER _U("ELb015")	/*! 数据集类型必须为矢量数据集*/
#define	UGS_INVALID_DT                          _U("ELb016")	/*! 非法数据集*/
#define	UGS_ISRASTER                            _U("ELb017")	/*! 数据集类型必须是普通栅格数据集*/
#define	UGS_ISMBRASTER                          _U("ELb018")	/*! 数据集类型必须是多波段栅格数据集*/
#define	UGS_APPENDING_DATASET_RECORD_FIELD_MATCHING_FAILD _U("ELb019")	/*! 追加的数据集没有匹配的字段*/

// 各种操作错误，包括数据源，数据集等的打开、关闭、创建、删除等操作
#define	UGS_NO_ALIAS_IN_WORKSPACE               _U("ELc001")	/*! 工作空间中没有别名为%s的数据源*/
#define	UGS_NO_INDEX_IN_WORKSPACE               _U("ELc002")	/*! 工作空间中没有索引为%d的数据源*/
#define	UGS_INSERT_DATASOURCE_ALIAS_FAILED_S    _U("ELc003")	/*! 插入别名为%s的数据源失败*/
#define	UGS_DATASOURCE_FAILED_TO_RENAME         _U("ELc004")	/*! 修改数据源别名失败*/
#define	UGS_DATASOURCE_FAILED_TO_FIND_ALIAS     _U("ELc005")	/*! 查找数据源别名失败*/
#define	UGS_DATASOURCE_FAILED_TO_GET_ALIAS      _U("ELc006")	/*! 获取数据源别名失败*/
#define	UGS_NEW_ALIAS_IS_EXIST_MODIFY_DATASOURCE_ALIAS_FAILED _U("ELc007")	/*! 新别名%s已经存在，修改数据源别名失败*/
#define	UGS_ENG_OPEN_DATASOURCE_FAILED          _U("ELc008")	/*! 打开数据源失败*/
#define	UGS_FAILED_TO_OPEN_DATASOURCE_S         _U("ELc009")	/*! 打开数据源%s失败*/
#define	UGS_DS_IS_NOT_OPEN                      _U("ELc010")	/*! 数据源没有打开*/
#define	UGS_READ_SDBINFO_FAILED                 _U("ELc011")	/*! 读取文件型数据源信息失败*/
#define	UGS_ODBC_SET_DATAOURCEINFO_FAILED       _U("ELc012")	/*! 设置数据源信息失败*/
#define	UGS_OUTPUT_DATASOURCE_IS_NULL           _U("ELc013")	/*! 设置输出数据源失败*/
#define	UGS_FAILED_TO_READ_DATASOURCE_INFO      _U("ELc014")	/*! 读取数据源信息失败*/
#define	UGS_FAILED_TO_SAVE_DATASOURCE_INFO      _U("ELc015")	/*! 保存数据源信息失败*/
#define	UGS_DATASOURCE_FAILED_TO_RELEASE_AT     _U("ELc016")	/*! 释放数据源失败*/
#define	UGS_FAILED_TO_CREATE_DATASOURCE         _U("ELc017")	/*! 创建数据源失败*/
#define	UGS_DATASOURCE_FAILED_TO_CREATE_DATASET _U("ELc018")	/*! 创建数据集失败*/
#define	UGS_MAYBE_SUPERMAPDS_ALREADY            _U("ELc019")	/*! 可能已经是SuperMap的数据源*/
#define	UGS_BUFFER_ANALYSIS_CREATE_UDB_DATASOURCE_FAIL _U("ELc020")	/*! 创建缓冲区时，创建临时UDB数据源失败*/
#define	UGS_SQLPLUS_DELETEMETADATA_FAILED       _U("ELc021")	/*! SQL+引擎删除元数据失败*/
#define	UGS_DATASET_NOT_OPEN                    _U("ELc022")	/*! 数据集没有打开*/
#define	UGS_FAILED_TO_OPEN_DT                   _U("ELc023")	/*! 打开数据集失败*/
#define	UGS_NETWORK_NOT_OPEN                    _U("ELc024")	/*! 网络数据集没有打开*/
#define	UGS_FAILED_TO_OPEN_NETWORK              _U("ELc025")	/*! 网络数据集打开失败*/
#define	UGS_CANNOT_OPEN_TEMPLATE_DATASET        _U("ELc026")	/*! 模版数据集不能打开*/
#define	UGS_SQLPLUS_DS_OPEN_EXPANDTABLE_FAILED  _U("ELc027")	/*! 打开外挂属性表失败*/
#define	UGS_ODBC_TOPODATASET_OPEN_FAILED        _U("ELc028")	/*! 打开拓扑数据集失败*/
#define	UGS_ODBC_VECTOR_OPEN_FAILED             _U("ELc029")	/*! 打开矢量数据集失败*/
#define	UGS_DATASET_NOT_OPEN_OR_CANNOT_OPEN     _U("ELc030")	/*! 数据集没有打开或无法打开*/
#define	UGS_FAILED_TO_ADD_DATASET               _U("ELc031")	/*! 添加数据集失败*/
#define	UGS_FAILED_TO_COPY_FATASET              _U("ELc032")	/*! 复制数据集失败*/
#define	UGS_FAILED_TO_OPEN_APPENDING_DATASET    _U("ELc033")	/*! 追加的数据集打开失败*/
#define	UGS_FAILED_TO_OPEN_APPENDED_DATASET     _U("ELc034")	/*! 被追加的数据集打开失败*/
#define	UGS_FAILED_TO_CREATE_NETWORK_SUBDATASET _U("ELc035")	/*! 创建网络数据集的子数据集失败*/
#define	UGS_ENG_CREATE_DATASET_FAILED2          _U("ELc036")	/*! 创建数据集(名称:%s;类型:%d)失败*/
#define	UGS_CREATE_DATASET_S_FAILED             _U("ELc037")	/*! 创建数据集%s失败*/
#define	UGS_ODBC_VECTOR_CREATE_FAILED           _U("ELc038")	/*! 新建矢量数据集失败*/
#define	UGS_CONSTRUCT_DATASET_FAILED            _U("ELc039")	/*! 构造数据集失败*/
#define	UGS_FAILED_TO_ADD_TOPO                  _U("ELc040")	/*! 添加拓扑数据集失败*/
#define	UGS_DATASET_NOT_MODIFIED                _U("ELc041")	/*! 数据集没有修改*/
#define	UGS_TOPO_FAILED_TO_ADD_RULES            _U("ELc042")	/*! 拓扑数据集添加规则失败*/
#define	UGS_SQLPLUS_DELETE_SUBDATASET_FAILED    _U("ELc043")	/*! 删除子数据集失败*/
#define	UGS_SQLPLUS_DELETE_DATASET_FAILED       _U("ELc044")	/*! 删除数据集失败*/
#define	UGS_FAILED_TO_DELETE_FOR_NOT_FIND_SUBDATASET _U("ELc045")	/*! 未找到子数据集，删除失败*/
#define	UGS_DELETE_NONE                         _U("ELc046")	/*! 没有删除任何数据集*/
#define	UGS_DELETEMETADATA_INITDATASET_FAILED   _U("ELc047")	/*! 删除中间数据失败，初始化数据集失败*/
#define	UGS_FAILED_TO_GET_DATASET_POINTER       _U("ELc048")	/*! 获取数据集指针失败*/
#define	UGS_FAILED_TO_GET_DATASET_TYPE          _U("ELc049")	/*! 获取数据集类型失败*/
#define	UGS_NETWORK_FAILED_TO_GET_NODEDT        _U("ELc050")	/*! 获取网络点数据集失败*/
#define	UGS_FAILED_TO_GET_CENTERPOINT_SERVICE_DATASET _U("ELc051")	/*! 获取中心点服务数据集失败*/
#define	UGS_SQLPLUS_UPDATE_VECTOR_REGISTER_FAILED _U("ELc052")	/*! 更新矢量数据集注册信息失败*/
#define	UGS_SQLPLUS_UPDATE_RASTER_REGISTER_FAILED _U("ELc053")	/*! 更新栅格数据集注册信息失败*/
#define	UGS_DATASET_NOT_HAVE_THIS_REGISTER_OPTION _U("ELc054")	/*! 数据集不存在该注册选项*/
#define	UGS_DATASET_ALIAS_UPDATE_FAILED         _U("ELc055")	/*! 数据集别名更新失败*/
#define	UGS_ODBC_VECTOR_REGISTEROPTION_FAILED   _U("ELc056")	/*! 矢量数据集注册失败*/
#define	UGS_ODBC_VECTOR_UNREGISTEROPTION_FAILED _U("ELc057")	/*! 矢量数据集注销失败*/
#define	UGS_DATASET_FAILED_TO_GET_FIELD_INFO    _U("ELc058")	/*! 数据集得到字段信息失败*/
#define	UGS_ODBC_GET_DATASET_UPDATETIME_FAILED  _U("ELc059")	/*! 获取数据集更新时间失败*/
#define	UGS_ODBC_SETBOUNDS_FAILED               _U("ELc060")	/*! 设置数据集范围失败*/
#define	UGS_COMPUTEBOUNDS_FAILED                _U("ELc061")	/*! 计算数据集范围失败*/
#define	UGS_ODBC_VECTOR_APPEND_FAILED           _U("ELc062")	/*! 矢量数据集追加失败*/
#define	UGS_ODBC_VECTOR_GETNEWID_FAILED         _U("ELc063")	/*! 矢量数据集获取新的ID失败*/
#define	UGS_READ_DATASETS_FAILED                _U("ELc064")	/*! 获取矢量数据集所在文件夹指针失败*/
#define	UGS_FAILED_TO_READ_DATA                 _U("ELc065")	/*! 读取栅格数据失败*/
#define	UGS_FAILED_TO_GET_DATASET_INITIAL_INFO  _U("ELc066")	/*! 数据集初始信息获取失败*/
#define	UGS_FAILED_TO_INITIALIZE_DATASET        _U("ELc067")	/*! 初始化数据集失败*/
#define	UGS_CURRENT_DATASET_CANNOT_EDIT         _U("ELc068")	/*! 当前记录集不能编辑*/
#define	UGS_ODBC_RECORDSET_UPDATE_FAILED        _U("ELc069")	/*! 更新记录集失败*/
#define	UGS_SOURCE_RECORDSET_HASNO_RECORD       _U("ELc070")	/*! 源记录集没有记录*/
#define	UGS_FAILED_TO_APPEND_RECORDSET          _U("ELc071")	/*! 追加记录集失败*/
#define	UGS_RECORDSET_HAS_NO_GEOMETRY           _U("ELc072")	/*! 记录集中没有几何对象记录*/
#define	UGS_RS_IS_NOT_OPEN                      _U("ELc073")	/*! 记录集没有打开。*/
#define	UGS_NOT_FIND_THE_ID_IN_SELECTION        _U("ELc074")	/*! 没有在选择集中找到对应的ID*/
#define	UGS_HAVENOT_READ_ANY_DATA               _U("ELc075")	/*! 记录集没有读取到任何数据*/
#define	UGS_FAILED_TO_READ_FIELD_INFO           _U("ELc076")	/*! 获取数据表字段信息失败*/
#define	UGS_ODBC_TRUNCATE_TABLE_FAILED          _U("ELc077")	/*! 删除表中记录失败*/
#define	UGS_FAILED_TO_DELETE_RECORD             _U("ELc078")	/*! 删除记录失败*/
#define	UGS_ODBC_COMPUTERECCOUNT_FAILED         _U("ELc079")	/*! 计算记录数失败*/
#define	UGS_FAILED_TO_FETCH_DATA                _U("ELc080")	/*! 取数据失败*/
#define	UGS_UPTATE_FAILED                       _U("ELc081")	/*! 更新失败*/
#define	UGS_ODBC_GETRECORDCOUNT_FAILED          _U("ELc082")	/*! 获取记录数失败*/
#define	UGS_FETCH_DATA_FAILED                   _U("ELc083")	/*! 获取数据失败*/
#define	UGS_ODBC_FETCH_ID_FAILED                _U("ELc084")	/*! 获取记录ID失败*/
#define	UGS_HAS_NO_GEOMETRY                     _U("ELc085")	/*! 当前记录集不包含空间数据，不能执行空间数据相关操作。*/
#define	UGS_OPERATE_TEMPORARY_TABLE_FAILED      _U("ELc086")	/*! 操作临时表失败*/
#define	UGS_FAILED_TO_GET_TEMPTABLE             _U("ELc087")	/*! 获取临时关联表失败*/
#define	UGS_NO_SM_AND_NOT_EXPANDOPEN            _U("ELc088")	/*! 没有系统表，且非扩展打开*/
#define	UGS_ODBC_GETSYSTABLESELVALUE_FAILED     _U("ELc089")	/*! 获取某些系统表中特定字段的最大值失败*/
#define	UGS_NOT_SUPPORT_THIS_STATISTIC_MODE     _U("ELc090")	/*! 不支持此统计模式*/
#define	UGS_ODBC_FETCH_FOREIGHNTABLE_VALUE_FAILED _U("ELc091")	/*! 获取外接表值失败*/
#define	UGS_CREATE_WORKSPACE_SMTABLE_FAILED     _U("ELc092")	/*! 创建工作空间的系统表失败*/
#define	UGS_DATASET_ALREADY_EXIST_IN_REGEDIT    _U("ELc093")	/*! 注册表中已经存在相关记录*/
#define	UGS_FAILED_TO_CUT_FOR_FAILED_TO_COPY_TO_REGEDIT _U("ELc094")	/*! 拷贝到注册表失败，剪切失败*/
#define	UGS_REGISTER_TABLE_NOT_EXIST            _U("ELc095")	/*! 注册表不存在*/
#define	UGS_INCORRECT_EDIT_MODE                 _U("ELc096")	/*! 编辑模式错误*/
#define	UGS_IS_EDITING_AND_ALREADY_ADDED        _U("ELc097")	/*! 正在编辑且已经执行过添加操作*/
#define	UGS_LAST_EDIT_NOT_FINISH                _U("ELc098")	/*! 前一次编辑还没有结束*/
#define	UGS_ALREADY_IN_EDITING                  _U("ELc099")	/*! 已经是编辑状态*/
#define	UGS_EDITING_NOW_PLEASE_EDIT_AFTER       _U("ELc100")	/*! 当前正在编辑中，请更新或取消更新之后再编辑*/
#define	UGS_NOT_IN_EDTING_OR_NEVER_EDITED       _U("ELc101")	/*! 不在编辑状态，或没有进行过编辑*/
#define	UGS_HAVE_MODIFIED_AND_UPDATE_FAILED     _U("ELc102")	/*! 前面已经做过修改且更新失败*/
#define	UGS_NO_CHANGED                          _U("ELc103")	/*! 没有做任何修改*/
#define	UGS_NEEDNOT_UPDATE_FOR_NO_CHANGE        _U("ELc104")	/*! 没有发生改变，不需要更新*/
#define	UGS_FAILED_TO_CREATE_SMID_SERIAL        _U("ELc105")	/*! 创建SmID的序列失败*/
#define	UGS_ODBC_EXECUPDATE_FAILED              _U("ELc106")	/*! 执行更新失败*/
#define	UGS_SQLPLUS_GETSEQVALUE_FAILED          _U("ELc107")	/*! 得到序列化的值失败*/
#define	UGS_DELETE_FAILED                       _U("ELc108")	/*! 删除失败*/
#define	UGS_ODBC_GETKEY_FAILED                  _U("ELc109")	/*! 获取键值失败*/
#define	UGS_ODBC_FETCH_LINKTABLE_DATA_FAILED    _U("ELc110")	/*! 获取链接表数据失败*/
#define	UGS_FAILED_TO_CREATE_MULTIBAND_DATASET  _U("ELc111")	/*! 创建多波段栅格数据集失败*/
#define	UGS_FAILED_TO_CREATE_DATASOURCES        _U("ELc112")	/*! 创建数据源集合失败*/
#define	UGS_FAILED_TO_RENAME                    _U("ELc113")	/*! 重命名失败*/
#define	UGS_FAILED_TO_CREATE_SERIAL             _U("ELc114")	/*! 创建序列失败*/
#define	UGS_TOPO_FAILED_TO_CREATE_POINT         _U("ELc115")	/*! 创建拓扑点错误数据集失败*/
#define	UGS_TOPO_FAILED_TO_CREATE_LINE          _U("ELc116")	/*! 创建拓扑线错误数据集失败*/
#define	UGS_TOPO_FAILED_TO_CREATE_REGION        _U("ELc117")	/*! 创建拓扑面错误数据集失败*/
#define	UGS_TOPO_FAILED_TO_CREATE_DIRTYAREA     _U("ELc118")	/*! 创建拓扑脏区数据集失败*/
#define	UGS_TOPO_FAILED_TO_CREATE_POINT_S       _U("ELc119")	/*! 创建拓扑点错误数据集[%s]失败*/
#define	UGS_TOPO_FAILED_TO_CREATE_LINE_S        _U("ELc120")	/*! 创建拓扑线错误数据集[%s]失败*/
#define	UGS_TOPO_FAILED_TO_CREATE_REGION_S      _U("ELc121")	/*! 创建拓扑面错误数据集[%s]失败*/
#define	UGS_TOPO_FAILED_TO_CREATE_DIRTYAREA_S   _U("ELc122")	/*! 创建拓扑脏区数据集[%s]失败*/
#define	UGS_FETCH_DATA_FAILED_D                 _U("ELc123")	/*! 获取数据[id=%d]失败*/
#define	UGS_FAILED_TO_MAKEIMPORTPARAMS          _U("ELc124")	/*! 创建转换参数失败*/
#define	UGS_ENG_USE_DATASOURCE_FAILED           _U("ELc125")	/*! 使用数据源失败*/
#define	UGS_FAILED_TO_SETCHARSET                _U("ELc126")	/*! 设置字符集失败*/
#define	UGS_DATASET_FAILED_TO_SAVEINFO          _U("ELc127")	/*! 保存数据集信息失败*/
#define	UGS_DATASET_ALREADY_IN_TOPO_DATASET     _U("ELc128")	/*! 数据集已经添加到topo数据集*/
#define	UGS_LINKTABLE_NOT_SUPPROT_WRITE         _U("ELc129")	/*! 关联表不支持写操作*/
#define	UGS_NOT_SUPPORT_THIS_VERSION_OF_TEXTURE_MODEL _U("ELc130")	/*! 模型纹理版本信息非法*/
#define	UGS_ODBC_DATASET_APPEND_FAILED          _U("ELc131")	/*! 数据集追加失败!*/
#define	UGS_ODBC_DATASET_OPEN_FAILED            _U("ELc132")	/*! 数据集无法打开*/
#define	UGS_DATASOURCE_REFRESH_FAILD            _U("ELc133")	/*! 刷新数据源失败*/
#define	UGS_CREATE_TEMPORARY_DATASOURCE_FAILD   _U("ELc134")	/*! 创建临时数据源失败*/
#define	UGS_MAYBE_DELETED_BY_OTHER_THREAD       _U("ELc135")	/*! 可能已经被其它线程删除了*/
#define UGC_DYNAMIC_DATASET_NOT_SUPPORT_DELETE  _U("ELc136")	/*! 拥有动态分段角色的数据集不能被删除*/
#define UGC_DYNAMIC_FIELD_VALUE_EXCEED_RANGE    _U("ELc137")	/*! 动态分段FM或TM字段值超过超过范围*/
#define UGC_DYNAMIC_RESULT_CAN_NOT_SET			_U("ELc138")	/*! 动态分段结果数据集集合对象不能被直接修改*/
#define UGC_DATABASENAMEERR_FOR_SINGLEFILE      _U("ELc139")    /*! 单文件打开时数据库名必须设置成:memory:*/
#define UGS_OPEN_REGISTER_FAILED                _U("ELc140")    /*! 读取数据源系统表信息失败*/
#define UGS_DATASET_PIXELFORMAT_NOT_SUPPORT     _U("ELc141")    /*! 数据集 %s 的像素类型不支持,请使用高版本的桌面打开*/

// 各种分析类错误，包括网络分析、叠加分析、缓冲区分析、栅格分析动态分段校准等分析错误
#define	UGS_BUFFER_ANALYSIS_FAILED              _U("ELd001")	/*! 缓冲区分析失败*/
#define	UGS_FAILED_TO_SHORTPATH                 _U("ELd002")	/*! 最短路径分析失败*/
#define	UGS_FAILED_TO_PATH                      _U("ELd003")	/*! 路径分析失败*/
#define	UGS_FAILED_TO_MTSP                      _U("ELd004")	/*! 多旅行商分析失败*/
#define	UGS_FAILED_TO_TRACE                     _U("ELd005")	/*! 追踪分析失败*/
#define	UGS_LINE_INTERSECT_FAILED               _U("ELd006")	/*! 线段求交失败*/
#define	UGS_THE_BARRIER_EDGE                    _U("ELd007")	/*! 此边为障碍边*/
#define	UGS_NODE_IS_BARRIERNODE                 _U("ELd008")	/*! 此节点为障碍点*/
#define	UGS_VIRTUAL_NODES                       _U("ELd009")	/*! 此节点是虚节点*/
#define	UGS_FAILED_TO_SEARCHLOOP_BASEON_ARC     _U("ELd010")	/*! 基于弧段查询网络连通回路失败*/
#define	UGS_OUTPUT_TRN                          _U("ELd011")	/*! 输出转向表失败*/
#define	UGS_FAILED_TO_GET_CENTERPOINT           _U("ELd012")	/*! 得到中间点失败*/
#define	UGS_FAILED_TO_CHECK_DEMAND_POINTS       _U("ELd013")	/*! 检查需求点失败*/
#define	UGS_FAILED_TO_CREATE_ALLOT_POINTS_FILE  _U("ELd014")	/*! 创建分配点失败*/
#define	UGS_FAILED_TO_GET_NODE_ALLOT            _U("ELd015")	/*! 获取站点分配信息失败*/
#define	UGS_NO_BUSLINE_IN_BUSSTOP               _U("ELd016")	/*! 公交站点范围内无线路*/
#define	UGS_NO_BUSSTOP_IN_BUSLINE               _U("ELd017")	/*! 公交线路范围内无站点*/
#define	UGS_THE_DELETING_BUSLINE_NONENTITY      _U("ELd018")	/*! 指定要删除的公交线路不存在*/
#define	UGS_PATH_NO_MATCH_POINTS                _U("ELd019")	/*! 第i+1路由点无匹配的道路*/
#define	UGS_ROUTE_NODE_NO_MATCH_ROAD            _U("ELd020")	/*! 第i+1路由点无匹配的道路*/
#define	UGS_BUSLINE_HAS_NO_BUSSTOP              _U("ELd021")	/*! 线路无站点*/
#define	UGS_NO_BUSLINE_THROUGH_BUSSTOP          _U("ELd022")	/*! 该站点无线路通过*/
#define	UGS_NO_BUSSTOP_IN_UPDATE_BUSLINE        _U("ELd023")	/*! 更新线路范围内无站点*/
#define	UGS_FAILED_TO_GET_COST_PARAM            _U("ELd024")	/*! 获取花费参数失败*/
#define	UGS_FAILED_TO_GET_COST                  _U("ELd025")	/*! 获取花费失败*/
#define	UGS_FAILED_TO_GET_TRNCOST               _U("ELd026")	/*! 获取转向花费失败*/
#define	UGS_FAILED_TO_GET_TRACE_COST            _U("ELd027")	/*! 获取追踪花费失败*/
#define	UGS_FAILED_TO_CREATE_TRACEADJMATRIX     _U("ELd028")	/*! 创建追踪矩阵失败*/
#define	UGS_FAILED_TO_CREAT_ADJMATRIX           _U("ELd029")	/*! 创建邻接矩阵失败*/
#define	UGS_FAILED_BUILD_SINGLE_GRADE           _U("ELd030")	/*! 建立单个河流等级失败*/
#define	UGS_NODE_FAILED_CREATE_DIRECTION        _U("ELd031")	/*! 单个节点创建流向失败*/
#define	UGS_FAILED_TO_WORDSEGMENT               _U("ELd032")	/*! 分词失败*/
#define	UGS_FAILED_TO_GET_WORD_FREQUENCY        _U("ELd033")	/*! 得到词串频率失败*/
#define	UGS_FAILED_DELETE_POSTFIX               _U("ELd034")	/*! 删除后缀失败*/
#define	UGS_TRIANGLE_TOPO_ERROR                 _U("ELd035")	/*! 三角形拓扑关系错误*/
#define	UGS_DATASET_ATTACH_TOPO                 _U("ELd036")	/*! 数据集已经参与了拓扑检查，被拓扑数据集关联*/
#define	UGS_INVLAID_TOPO_RULES                  _U("ELd037")	/*! 非法的拓扑规则*/
#define	UGS_FAILED_CONVERT_ARC_TO_NODE          _U("ELd038")	/*! 弧段转化为节点失败*/
#define	UGS_PICKUP_COMMON_BOUNDARY_FAILED       _U("ELd039")	/*! 提取公共边界失败*/
#define	UGS_FAILED_TO_MARK                      _U("ELd040")	/*! 标识失败*/
#define	UGS_ODBC_ENHANCE_IDS_FAILED             _U("ELd041")	/*! 过滤ID失败*/
#define	UGS_FAILED_TO_PREPROCESS                _U("ELd042")	/*! 预处理失败*/
#define	UGS_NOT_GET_NODE_INFO                   _U("ELd043")	/*! 没有得到节点信息*/
#define	UGS_NOT_MATCH_THE_NODE                  _U("ELd044")	/*! 没有匹配到相关节点*/
#define	UGS_NO_CORRELATIVE_ARC                  _U("ELd045")	/*! 没有相关的弧段*/
#define	UGS_TRACE_INVALID_STARTNODE_AND_ENDNODE _U("ELd046")	/*! 追踪前后节点非法*/
#define	UGS_CANNOT_FIND_THE_CONNECTING_ENDNODE  _U("ELd047")	/*! 找不到连通的那个终点*/
#define	UGS_SELECT_WRONG_NODE                   _U("ELd048")	/*! 错误的统计模式*/
#define	UGS_NO_DIRTY_RECORD                     _U("ELd049")	/*! 没有脏区记录*/
#define	UGS_NONE_TIP_OR_TIP_ERROR               _U("ELd050")	/*! 没有提示信息或提示信息不正确*/
#define	UGS_ADJMATRIX_IS_NULL                   _U("ELd051")	/*! 邻接矩阵为空*/
#define	UGS_FAILED_TO_SERVICEAREA_ANALYSE       _U("ELd052")	/*! 服务区分析失败*/
#define	UGS_INCORRECT_ANALYSE_TYPE              _U("ELd053")	/*! 分析类型不正确*/
#define	UGS_FAILED_TO_IMPORT_TOPO_RULE          _U("ELd054")	/*! 导入拓扑规则失败*/
#define	UGS_OVERLAP_FAILED_TO_TOPO              _U("ELd055")	/*! 叠加分析拓扑处理失败*/
#define	UGS_FAILED_TO_GETCOVERSIGN              _U("ELd056")	/*! 得到服务覆盖面信息失败*/
#define	UGS_SHORT_OF_FEILDS                     _U("ELd057")	/*! 加载的属性表缺少字段，必须包含_U("StopID")、_U("MergeStopID")、_U("Position").*/
#define	UGS_NO_ROUTE                            _U("ELd058")	/*! 无对应路由*/
#define	UGS_NO_MEASURE                          _U("ELd059")	/*! 无对应刻度*/
#define	UGS_LESS_THAN_MIN                       _U("ELd060")	/*! 小于最小刻度*/
#define	UGS_GREATER_THAN_MAX                    _U("ELd061")	/*! 大于最大刻度*/
#define	UGS_STATIONS_FIND_SAME					_U("ELd062")	/*! 发现站点%d与站点%d相同，失败*/
#define	UGS_INPUT_ID_DOESNOT_EXIST				_U("ELd063")	/*! 输入站点不存在*/
#define	UGS_ONLY_SUPPORT_TWO_ID					_U("ELd064")	/*! 只支持通过两个站点ID搜索的模式*/
#define	UGS_INPUT_NUMBER_NOT_BETWEEN_1_TO_5		_U("ELd065")	/*! 输入的换乘方案数不在1和5之间ID搜索的模式*/
#define	UGS_RESULT_FAILED						_U("ELd066")	/*! 中心点%d求解失败，有%d个点无法到达*/
#define UGS_NO_GEOMETRY                         _U("ELd067")    /*! 不是几何对象*/
#define UGS_OUT_OF_BOUNDS                       _U("ELd068")    /*! 点不在bounds内*/
#define UGS_GRID_NO_LINE				        _U("ELd069")    /*! 格子内无线*/
#define UGS_OUT_OF_GRID                         _U("ELd070")    /*! 点没有在格子范围内*/
#define UGS_NO_ROUTEID                          _U("ELd071")    /*! 点没有对应的RouteID*/
#define UGS_OUT_OF_TOLERANCE                    _U("ELd072")    /*! 点没有在容限范围内*/
#define UGS_SAME_POINT                          _U("ELd073")    /*! 重复点*/
#define UGS_RIGHT_POINT                         _U("ELd074")    /*! 正确点*/
#define UGS_GAP_POINT                           _U("ELd075")    /*! 间隙点*/
#define UGS_NOMEASURE_POINT                     _U("ELd076")    /*! 无值点*/
#define UGS_NOTMONOTONY_POINT                   _U("ELd077")    /*! 非单调点*/
#define UGS_RIGHT_LINE                          _U("ELd078")    /*! 正确线*/
#define UGS_PARTMATCH                           _U("ELd079")    /*! 部分匹配*/
#define UGS_NOMATCH                             _U("ELd080")    /*! 完全不匹配*/
#define UGS_STARTISEND                          _U("ELd081")    /*! 首尾刻度相同*/
#define UGS_LINEINVALID                         _U("ELd082")    /*! 折线非法*/
#define UGS_ERR_CALPARAM						_U("ELd083")	/*! 计算转换参数(只做系数计算和计算误差)错误*/
#define UGS_IMGREG_ERR_INTERRECTIFY             _U("ELd084")    /*! 解方程错误,无法求出系数!请增加或修改控制点!*/
#define UGS_FAILED_CALCUREPARAM					_U("ELd085")	/*! 求解%s方向的加权后的转换参数失败*/
#define UGS_FAILED_CALPARAM                     _U("ELd086")    /*! 计算转换参数失败*/
#define UGS_FAILED_RECTIFYMBR					_U("ELd087")    /*! 计算变换后的地理坐标范围失败*/
#define UGS_INVALID_RECITYMETHOD  				_U("ELd088")    /*! 无效的配准方法*/
#define UGS_FAILED_MIDDLE_RESAMPLE              _U("ELd089")    /*! 对中间配准结果进行重采样失败*/
#define UGS_FAILED_NEIGHBORESTRESAMPLE			_U("ELd090")	/*! 最邻近元重采样失败*/
#define UGS_FAILED_CALGEOREFERENCE				_U("ELd091")	/*! 计算地理参考范围失败*/
#define UGS_COUNT_ZERO_RECITYERROR				_U("ELd092")    /*! 配准误差信息数目为0*/
#define UGS_ORIGINAL_TARGET_POINTS_DIFFERNT_SIZE _U("ELd093")   /*! 待配准图层上的控制点与参考图层上的控制点点数目不等*/
#define UGS_POINT_COUNTS_LESS_TWO				_U("ELd094")    /*! 非法参数: 点数目小于2*/
#define UGS_POINT_COUNTS_LESS_THREE				_U("ELd095")	/*! 非法参数: 点数目小于3*/
#define UGS_FAILED_RECTIFY_VECTOR_ORIGIN_DATASET _U("ELd096")   /*! 直接在源数据集之上进行配准失败*/
#define UGS_ERR_CADDATASET_RECT                 _U("ELd097")	/*! 非法参数: CAD数据集只支持矩形配准*/
#define UGS_FAILED_RESAMPLE_AFTER_NEIGHBOREST   _U("ELd098")	/*! 栅格数据集配准后再进行重采样失败*/
#define UGS_RESAMPLING                          _U("ELd099")    /*! 正在进行数据集重采样处理...*/
#define UGS_TEMP_DATA                           _U("ELd100")    /*! 正在处理临时数据...*/
#define UGS_SMOOTHING                           _U("ELd101")    /*! 正在进行数据集光滑处理...*/
#define UGS_GAP_LINE                            _U("ELd102")    /*! 间隙线*/
#define	UGS_BUSLINE_HAS_ONE_BUSSTOP             _U("ELd103")	/*! 线路仅有一个站点*/
#define	UGS_BUSSTOP_NOT_EXIST					_U("ELd104")	/*! 公交站点不在数据集中*/
#define	UGS_BUSLINE_NOT_EXIST					_U("ELd105")	/*! 公交线路不在数据集中*/
#define	UGS_SAME_ID					            _U("ELd106")	/*! 重复ID*/

#define UGS_BUFFERANALYST_BUILDING_MATRIX_FAILED _U("ELd107")   /*! 构建邻接矩阵失败*/
#define UGS_BUFFERANALYST_BUILDING_REGION_FAILED _U("ELd108")	/*! 缓冲区构面失败*/
#define UGS_BUFFERANALYST_UNION_REGION_FAILED   _U("ELd109")    /*! 缓冲区合并面失败, INDEX=%d*/
#define UGS_BUFFERANALYST_UNION_K_VALUE_INVALID _U("ELd110")    /*! 缓冲区合并面，k值无效，合并面失败, INDEX=%d*/
#define UGS_BUFFERANALYST_UNION_SUBLINE_BEGIN   _U("ELd111")    /*! 开始进行合并子线的操作*/
#define UGS_BUFFERANALYST_UNION_SUBLINE_END     _U("ELd112")    /*! 合并子线的操作完成*/
#define UGS_BUFFERANALYST_BREAK_CLEAR_LINE_BEGIN _U("ELd113")   /*! 开始进行打断线清除线操作*/
#define UGS_BUFFERANALYST_BREAK_CLEAR_LINE_END  _U("ELd114")    /*! 打断线清除线操作完成*/
#define UGS_BUFFERANALYST_UNION_SUBREGION_BEGIN _U("ELd115")    /*! 开始进行合并子面操作*/
#define UGS_BUFFERANALYST_UNION_SUBREGION_END   _U("ELd116")    /*! 合并子面操作完成*/
#define UGS_BUFFERANALYST_CLEAR_SUBREGION_WRONG _U("ELd117")    /*! %d和%d面对像进行合并面对象中的清除线操作异常*/
#define UGS_BUFFERANALYST_DIFFERENCE_FAILED     _U("ELd118")    /*! 面对像裁剪失败*/
#define UGS_POSITION_NOT_MATCH					_U("ELd119")	/*! 空间位置不匹配*/

#define UGS_BUFFERANALYST_BUILDING_MATRIX_END   _U("ELd120")    /*! 构建邻接矩阵完成*/
#define UGS_BUFFERANALYST_PRO_SEG_SEF_REL_START _U("ELd121")    /*! 开始处理自相交邻接矩阵信息*/
#define UGS_BUFFERANALYST_PRO_SEG_SEF_REL_END   _U("ELd122")    /*! 处理自相交邻接矩阵信息完成*/
#define UGS_BUFFERANALYST_BUILDING_REGION_COMP  _U("ELd123")    /*! 邻接矩阵构面完成*/
#define UGS_BUFFERANALYST_BUILDING_REGION_START _U("ELd124")    /*! 开始构面*/
#define UGS_BUFFERANALYST_CLERA_BREAK_LINE      _U("ELd125")    /*! 正在清除非法线*/
#define UGS_BUFFERANALYST_MERGE_PART_SEG        _U("ELd126")    /*! 正在合并碎线*/
#define UGS_BUFFERANALYST_BUILDING_REGION       _U("ELd127")    /*! 正在构建面对象*/
#define UGS_BUFFERANALYST_BUILDING_MATRIX_START _U("ELd128")    /*! 开始构建邻接矩阵*/

#define UGS_HAVE_NOT_ARCNAME					_U("ELd129")	/*! 没有设置弧段名称字段*/
#define UGS_NOT_MATCH_POINT						_U("ELd130")	/*! 第%d个点没有被捕捉*/

// 引擎各种状态特征不匹配，（数据库当前事务，时序，版本等的状态不适合某类操作）
#define	UGS_ODBC_DS_DISPOSE_VERSION_FAILED      _U("ELe001")	/*! 处理版本失败*/
#define	UGS_DATASETVECTOR_VERSION_REGISTEROPTION_FAILED _U("ELe002")	/*! SQLPLUS矢量数据集版本注册失败*/
#define	UGS_FAILED_TO_COMMIT_VERSION            _U("ELe003")	/*! 提交版本失败*/
#define	UGS_FAILED_TO_REGISTER_VERSION          _U("ELe004")	/*! 注册版本失败*/
#define	UGS_FAILED_TO_ROLLBACK                  _U("ELe005")	/*! 回滚失败*/
#define	UGS_FAILED_TO_TRANSCOMMIT_DATA          _U("ELe006")	/*! 提交数据失败*/
#define	UGS_HAVE_UNCOMMITTABLE_DATA_AND_FAILED_TO_AUTOCOMMIT _U("ELe007")	/*! 存在未提交的编辑，且自动提交失败*/
#define	UGS_ODBCCONNECTION_SQLENDTRAN_FAILED    _U("ELe008")	/*! 长事务回滚失败*/
#define	UGS_NOT_OPEN_BY_TRANS                   _U("ELe009")	/*! 不是以事务方式打开*/
#define	UGS_FAILED_TO_START_TRANSACTION         _U("ELe010")	/*! 开始事务失败*/
#define	UGS_NOT_START_TRANSACTION               _U("ELe011")	/*! 未开始事务*/
#define	UGS_VERSION_NOT_SUPPORT                 _U("ELe012")	/*! 版本暂不支持该功能*/
#define	UGS_INIT_VERSION_ENVIRONMENT            _U("ELe013")	/*! 初始化版本环境失败*/
#define	UGS_VERSION_NOT_EXIST                   _U("ELe014")	/*! 版本不存在*/
#define	UGS_FAILED_TO_DELETE_VERSION            _U("ELe015")	/*! 删除版本失败*/
#define	UGS_VERSION_FAILED_TO_CREATE_REGEDIT    _U("ELe016")	/*! 创建版本管理系统表失败*/
#define	UGS_VERSION_FAILED_TO_ADD_EXTENT_INFO   _U("ELe017")	/*! 版本数据集添加扩展信息失败*/
#define	UGS_FAILED_TO_LOG_DUPLICATE_INFO        _U("ELe018")	/*! 记录复本信息失败*/
#define	UGS_FAILED_TO_CREATE_DUPLICATE_REGSYSTABLE _U("ELe019")	/*! 创建主复本系统表失败*/
#define	UGS_SUB_DUPLICATE_IS_EXISTED            _U("ELe020")	/*! 子复本数据集已存在*/
#define	UGS_FAILED_TO_CREATE_SUB_DUPLICATE      _U("ELe021")	/*! 创建子复本数据集失败*/
#define	UGS_FAILED_TO_CREATE_SUB_DUPLICATE_FIELDS _U("ELe022")	/*! 创建子复本字段失败*/
#define	UGS_FAILED_TO_COPY_DATA                 _U("ELe023")	/*! 复制数据失败*/
#define	UGS_DATASOURCE_NOT_SUPPORT_TO_CRETE_SUB_DUPLICATE _U("ELe024")	/*! 数据源不支持创建子复本*/
#define	UGS_FAILED_TO_CREATE_SUB_DUPLICATE_REGSYSTABLE _U("ELe025")	/*! 创建子复本系统表失败*/
#define	UGS_FAILED_TO_UPDATE_DUPLICATE          _U("ELe026")	/*! 复本更新操作失败*/
#define	UGS_DUPLICATE_IS_NOT_EXISTED            _U("ELe027")	/*! 复本数据集不存在*/
#define	UGS_PARENTS_VERSION_IS_NOT_EXISTED      _U("ELe028")	/*! 父版本不存在*/
#define	UGS_AIMED_VERSION_IS_NOT_PARENTS_VERSION _U("ELe029")	/*! 目标版本不是当前版本的父版本*/
#define	UGS_SUBVERSION                          _U("ELe030")	/*! 当前版本存在子版本*/
#define	UGS_FAILED_TO_CHANGE_VERSION            _U("ELe031")	/*! 切换版本失败*/
#define	UGS_FAILED_TO_RECONCILE                 _U("ELe032")	/*! 版本协调失败*/
#define	UGS_FAILED_TO_UNREGISTER_VERSION        _U("ELe033")	/*! 反注册版本失败*/
#define	UGS_FAILED_TO_COPYSERIES                _U("ELe034")	/*! 版本复制系列操作失败*/
#define	UGS_FAILED_TO_CREATE_DUPLICATE_REGEDIT  _U("ELe035")	/*! 创建复本系统表失败*/
#define	UGS_DUPLICATE_FAILED_TO_UPDATENAME      _U("ELe036")	/*! 更新复本名称失败*/
#define	UGS_DUPLICATE_FAILED_TO_UPDATEDESCRIPTION _U("ELe037")	/*! 更新复本描述失败*/
#define	UGS_DUPLICATE_FAILED_TO_GETDUPLICATEDATASET _U("ELe038")	/*! 获取复本数据集失败*/
#define	UGS_FAILED_TO_GETDUPLICATEINFOS         _U("ELe039")	/*! 获取复本信息失败*/
#define	UGS_FAILED_TO_EXPORTDIFFMESSAGE         _U("ELe040")	/*! 导出差异包失败*/
#define	UGS_NO_DIFFERENCE                       _U("ELe041")	/*! 无差异数据*/
#define	UGS_FAILED_TO_FETCHDATABYSQL            _U("ELe042")	/*! 取复本更新数据失败*/
#define	UGS_FAILED_TO_CREATEDUPLICATE           _U("ELe043")	/*! 创建复本失败*/
#define	UGS_FAILED_TO_DROPINVALIDDATA_A         _U("ELe044")	/*! 删除A表中的无效记录失败*/
#define	UGS_FAILED_TO_DROPINVALIDDATA_D         _U("ELe045")	/*! 删除D表中的无效记录失败*/
#define	UGS_FAILED_TO_DROPINVALIDDATA           _U("ELe046")	/*! 删除无效记录失败*/
#define	UGS_VERSION_FAILED_TO_SAVE              _U("ELe047")	/*! 版本保存失败*/
#define	UGS_HAS_CONFILIC                        _U("ELe048")	/*! 存在冲突*/
#define	UGS_FAILED_TO_DELETE_CURVERSION         _U("ELe049")	/*! 不能删除当前版本*/
#define	UGS_FAILED_TO_DELETE_ROOTS_VERSION      _U("ELe050")	/*! 不能删除根版本*/
#define	UGS_FAILED_TO_CREATEDIFFMSG             _U("ELe051")	/*! 创建差异包失败*/
#define	UGS_FAILED_TO_IMPORTDIFFMSG             _U("ELe052")	/*! 导入差异包失败*/
#define	UGS_NO_DIFFMSG                          _U("ELe053")	/*! 差异包不存在*/
#define	UGS_DIFFMSG_FAILED_TO_CREATETABLE       _U("ELe054")	/*! 创始差异包数据信息表失败*/
#define	UGS_DIFFMSG_FAILED_TO_APPENDDATA        _U("ELe055")	/*! 差异包追加数据失败*/
#define	UGS_ENGINETYPE_ILLEGAL                  _U("ELe056")	/*! 不支持的引擎类型*/
#define	UGS_WMS_WCS_NOT_SUPPORT_COPYDATASET     _U("ELe057")	/*! WMS和WCS数据集不可以执行数据集复制操作*/
#define	UGS_FAILED_TO_CREATEVERSION             _U("ELe058")	/*! 创建版本失败*/
#define	UGS_VERSION_EXISTED                     _U("ELe059")	/*! 版本已存在*/
#define	UGS_DT_NEED_NOT_RECONCILE               _U("ELe060")	/*! 当前数据集不是协调状态*/
#define	UGS_EDITBULKOPERATE_NOT_SUPPORT_DELETE  _U("ELe061")	/*! 批量编辑状态暂不支持删除操作*/
#define	UGS_FAILED_TO_UPDATE_A_TABLE            _U("ELe062")	/*! 更新A表数据失败*/
#define	UGS_HAS_STARTED_TRANSACTION             _U("ELe063")	/*! 已经开始事务*/
#define	UGS_AIMED_VERSION_UPDATED_AND_NEED_RECONCLIE _U("ELe064")	/*! 目标版本被更新，请重新协调*/
#define	UGS_DISOBEYED_WCS_LIMIT                 _U("ELe065")	/*! 违返wcs约束条件*/
#define	UGS_LAYER_IS_NULL                       _U("ELe066")	/*! 图层为空*/
#define	UGS_SETPPJCOORDSYS_FAIL                 _U("ELe067")	/*! 数据集不为空，Oracle Spatial不允许设置投影*/


// 数据库连接错误
#define	UGS_USERNAME_IS_EMPTY                   _U("ELf001")	/*! 用户名为空*/
#define	UGS_ENG_DATASOURCE_CONNECT_FAILED       _U("ELf002")	/*! 数据库连接失败，请检查数据源连接参数*/
#define	UGS_FAILED_INITIALIZE                   _U("ELf003")	/*! 分配ODBC环境信息失败*/
#define	UGS_FAILED_ALLOT_HANDLE                 _U("ELf004")	/*! 分配环境句柄失败*/
#define	UGS_FAILED_TO_CONNECT_DB                _U("ELf005")	/*! 连接数据库失败*/
#define	UGS_ODBCCONNECTION_INITALIZE_FAILED     _U("ELf006")	/*! 初始化连接失败*/
#define	UGS_ODBC_DS_CONNECT_FAILED              _U("ELf007")	/*! 数据源建立连接失败*/
#define	UGS_ODBC_GETALLDBINFO_FAILED            _U("ELf008")	/*! 获取数据库服务中所有数据库用户信息失败*/
#define	UGS_CANNOT_GET_CONNECTION_INFO          _U("ELf009")	/*! 得到连接信息失败*/
#define	UGS_FAILED_TO_HAVEDATABASE              _U("ELf010")	/*! 判断连接中的数据库是否存在失败*/
#define	UGS_FAILED_TO_READ_DATABASE             _U("ELf011")	/*! 读取数据库失败*/

// 引擎功能不一致问题
#define	UGS_SDB_NOT_SUPPORT_TOPO                _U("ELg001")	/*! SDB引擎暂时不支持Topo数据集*/
#define	UGS_UDB_NOT_SUPPORT_DELETEALL           _U("ELg002")	/*! UDB 引擎不支持全部删除操作*/
#define	UGS_UDB_NOT_SUPPORT_GETREACORDCHECKEDBY _U("ELg003")	/*! UDB 引擎不支持查询当前记录的锁定用户（长事务）*/
#define	UGS_UDB_NOT_SUPPORT_THIS_VECTOR_TYPE    _U("ELg004")	/*! UDB 引擎不支持这种矢量数据集类型*/
#define	UGS_UDB_NOT_SUPPORT_DELETE_FIELD        _U("ELg005")	/*! UDB引擎不支持删除字段*/
#define	UGS_UDB_NOT_SUPPORT_RELEASEPYRAMIDDATASETS _U("ELg006")	/*! UDB 引擎不支持如下操作:ReleasePyramidDatasets()*/
#define	UGS_UDB_NOT_SUPPORT_TIER                _U("ELg007")	/*! UDB 引擎不支持如下操作:Tier()*/
#define	UGS_UDB_NOT_SUPPORT_BULIDPYRAMID        _U("ELg008")	/*! UDB 引擎不支持如下操作:BuildPyramid()*/
#define	UGS_UDB_NOT_SUPPORT_REMOVEPYRAMIDS      _U("ELg009")	/*! UDB 引擎不支持如下操作:RemovePyramids()*/
#define	UGS_UDB_NOT_SUPPORT_CALCAVGVALUE        _U("ELg010")	/*! UDB 引擎不支持如下操作:CalcAvgValue()*/
#define	UGS_UDB_NOT_SUPPORT_GETLOCKEDUSERID     _U("ELg011")	/*! UDB 引擎不支持如下操作:GetLockedUserID()*/
#define	UGS_UDB_NOT_SUPPORT_CREATE              _U("ELg012")	/*! UDB 引擎不支持如下操作:Create()*/
#define	UGS_UDB_NOT_SUPPORT_COMPUTERECCOUNT     _U("ELg013")	/*! UDB 引擎不支持如下操作:ComputeRecCount()*/
#define	UGS_UDB_NOT_SUPPORT_RESAMPLE            _U("ELg014")	/*! UDB 引擎不支持如下操作:Resample()*/
#define	UGS_UDB_NOT_SUPPORT_REGISTEROPTION      _U("ELg015")	/*! UDB 引擎不支持如下操作:RegisterOption()*/
#define	UGS_UDB_NOT_SUPPORT_UNREGISTEROPTION    _U("ELg016")	/*! UDB 引擎不支持如下操作:UnRegisterOption()*/
#define	UGS_UDB_NOT_SUPPORT_GETCACHEFILE        _U("ELg017")	/*! UDB 引擎不支持如下操作:GetCacheFile()*/
#define	UGS_UDB_NOT_SUPPORT_COPYFIELD           _U("ELg018")	/*! UDB 引擎不支持如下操作:CopyField()*/
#define	UGS_UDB_NOT_SUPPORT_GETGEOMETRYDIRECT   _U("ELg019")	/*! UDB 引擎不支持如下操作:GetGeometryDirect()*/
#define	UGS_UDB_NOT_SUPPORT_FINDFIRST           _U("ELg020")	/*! UDB 引擎不支持如下操作:FindFirst()*/
#define	UGS_UDB_NOT_SUPPORT_FINDLAST            _U("ELg021")	/*! UDB 引擎不支持如下操作:FindLast()*/
#define	UGS_UDB_NOT_SUPPORT_FINDNEXT            _U("ELg022")	/*! UDB 引擎不支持如下操作:FindNext()*/
#define	UGS_UDB_NOT_SUPPORT_FINDPREV            _U("ELg023")	/*! UDB 引擎不支持如下操作:FindPrev()*/
#define	UGS_UDB_NOT_SUPPORT_SETGEOMETRY         _U("ELg024")	/*! UDB 引擎不支持如下操作:SetGeometry*/
#define	UGS_UDB_NOT_SUPPORT_SETFIELDVALUE       _U("ELg025")	/*! UDB 引擎不支持如下操作:SetFieldValue*/
#define	UGS_UDB_NOT_SUPPORT_SETFIELDVALUENULL   _U("ELg026")	/*! UDB 引擎不支持如下操作:SetFieldValueNull*/
#define	UGS_UDB_NOT_SUPPORT_LOCK                _U("ELg027")	/*! UDB 引擎不支持如下操作:Lock()*/
#define	UGS_UDB_NOT_SUPPORT_UNLOCK              _U("ELg028")	/*! UDB 引擎不支持如下操作:UnLock()*/
#define	UGS_UDB_NOT_SUPPORT_UNDOCHECKOUT        _U("ELg029")	/*! UDB 引擎不支持如下操作:UndoCheckOut()*/
#define	UGS_UDB_NOT_SUPPORT_UNDOCHECKOUTCURRENT _U("ELg030")	/*! UDB 引擎不支持如下操作:UndoCheckOutCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKINCURRENT      _U("ELg031")	/*! UDB 引擎不支持如下操作:CheckInCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKOUTCURRENT     _U("ELg032")	/*! UDB 引擎不支持如下操作:CheckOutCurrent()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKIN             _U("ELg033")	/*! UDB 引擎不支持如下操作:CheckIn()*/
#define	UGS_UDB_NOT_SUPPORT_CHECKOUT            _U("ELg034")	/*! UDB 引擎不支持如下操作:CheckOut()*/
#define	UGS_CREATING_WEBENGINE_IS_NONSUPPORT    _U("ELg035")	/*! 网络数据引擎不支持创建操作*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_RASTER _U("ELg036")	/*! 网络数据引擎不支持创建栅格数据集*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_TOPO _U("ELg037")	/*! 网络数据引擎不支持创建拓扑数据集*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_CREATE_VECTOR _U("ELg038")	/*! 网络数据引擎不支持创建矢量数据集*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_ROLLBACK   _U("ELg039")	/*! 网络数据引擎不支持回滚操作*/
#define	UGS_WEBENGINE_NOT_SUPPORT_TO_COMMIT     _U("ELg040")	/*! 网络数据引擎不支持提交操作*/
#define	UGS_WEBENGINE_NOT_SUPPORT_BEGINTRANS    _U("ELg041")	/*! 网络数据引擎不支持开始事务操作*/
#define	UGS_WCS_NOT_SUPPORT_SETVISIBLE_LAYER    _U("ELg042")	/*! 网络数据引擎的WCS数据集不支持设置可见图层的操作*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERINDEXES _U("ELg043")	/*! 网络数据引擎的WCS数据集不支持获取可见图层索引*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERTILES _U("ELg044")	/*! 网络数据引擎的WCS数据集不支持获取可见图层标题*/
#define	UGS_WCS_NOT_SUPPORT_GETVISIBLELAYERNEMES _U("ELg045")	/*! 网络数据引擎的WCS数据集不支持获取可见图层名称*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERINDEXS   _U("ELg046")	/*! 网络数据引擎的WCS数据集不支持获取所有图层的索引*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERTITLES   _U("ELg047")	/*! 网络数据引擎的WCS数据集不支持获取所有图层的标题*/
#define	UGS_WCS_NOT_SUPPORT_GETALLLAYERNAMES    _U("ELg048")	/*! 网络数据引擎的WCS数据集不支持获取所有图层的名称*/
#define	UGS_WFS_REQUEST_TO_PRODUCE_MEMORY_DATASOURCE_IS_FAILED _U("ELg049")	/*! WFS GetFeature请求未生成内存数据源*/
#define	UGS_WMS_REQUEST_TO_PRODUCE_MEMORY_DATASOURCE_IS_FAILED _U("ELg050")	/*! WMS GetMap请求未生成内存数据源*/
#define	UGS_SAVEINFO_UNFULFILMENT               _U("ELg051")	/*! 加载SUW文件版本号和信息的接口未实现*/

// 鼠标响应时间错误
#define	UGS_FAILED_TO_ONMOUSEMOVE               _U("ELh001")	/*! 响应鼠标移动事件失败*/
#define	UGS_FAILED_TO_ONLBUTTONDOWN             _U("ELh002")	/*! 响应鼠标左键单击事件失败*/
#define	UGS_FAILED_TO_ONRBUTTONDBCLK            _U("ELh003")	/*! 响应鼠标右键双击事件失败*/
#define	UGS_FAILED_TO_ONRBUTTONDOWN             _U("ELh004")	/*! 响应鼠标右键单击事件失败*/
#define	UGS_FAILED_TO_ONRBUTTONUP               _U("ELh005")	/*! 响应鼠标右键弹起事件失败*/
#define	UGS_FAILED_ONLBUTTONUP                  _U("ELh006")	/*! 响应鼠标左键弹起失败*/
#define	UGS_FAILED_TO_ONREDO                    _U("ELh007")	/*! 重做失败*/
#define	UGS_FAILED_TO_ONSETCURSOR               _U("ELh008")	/*! 设置光标失败*/
#define	UGS_FAILED_TO_ONUNDO                    _U("ELh009")	/*! 撤销失败*/
#define	UGS_FAILED_TO_ONCUT                     _U("ELh010")	/*! 剪切失败*/
#define	UGS_FAILED_TO_ONDELETE                  _U("ELh011")	/*! 删除失败*/
#define	UGS_IMPORT_DATA_FAILED                  _U("ELh012")	/*! 数据导入失败*/
#define	UGS_FAILED_TO_PASTE                     _U("ELh013")	/*! 粘贴失败*/
#define	UGS_FAILED                              _U("ELh014")	/*! %s操作失败*/
#define	UGS_FAILED_TO_ONLBUTTONDBCLK            _U("ELh015")	/*! 响应鼠标左键双击事件失败*/

// 接口未实现
#define	UGS_GETINFO_UNFULFILMENT                _U("ELi001")	/*! 获得数据库版本工作空间信息的接口未实现*/
#define	UGS_GETTABADJUST_UNFULFILMENT           _U("ELi002")	/*! 获取xml标签应在位置的接口未实现*/
#define	UGS_READCONTENT_UNFULFILMENT            _U("ELi003")	/*! 从文件中读取字节数的接口未实现*/
#define	UGS_UNFULFILMENT                        _U("ELi004")	/*! 接口%s未实现*/

// 第三方库的错误
#define	UGS_ICU_ERROR                           _U("ELj001")	/*! ICU错误:%s*/
#define	UGS_SQL_ERROR                           _U("ELj002")	/*! SQL数据库错误:%s*/
#define	UGS_ORACLE_ERROR                        _U("ELj003")	/*! ORACLE数据库错误:%s*/
#define	UGS_MYSQL_ERROR                         _U("ELj004")	/*! MYSQL数据库错误:%s*/
#define	UGS_KINGBASE_ERROR                      _U("ELj005")	/*! KINGBASE数据库错误:%s*/
#define	UGS_DB2_ERROR                           _U("ELj006")	/*! DB2数据库错误:%s*/
#define	UGS_INFORMIX_ERROR                      _U("ELj007")	/*! INFORMIX数据库错误:%s*/
#define	UGS_HTTP_ERROR_NUMBER_OVERRUN           _U("ELj008")	/*! HTTP 错误号大于300*/
#define	UGS_WMS_SERVER_REPORT_AN_EXCEPTION      _U("ELj009")	/*! WMS服务器报告了一个异常*/
#define	UGS_WFS_SERVER_REPORT_AN_EXCEPTION      _U("ELj010")	/*! WFS服务器报告了一个异常*/
#define	UGS_WCS_SERVER_REPORT_AN_EXCEPTION      _U("ELj011")	/*! WCS服务器报告了一个异常*/
#define	UGS_OGC_SERVER_REPORT_AN_EXCEPTION      _U("ELj012")	/*! OGC 网络服务器报告了一个异常*/
#define	UGS_SQLITE_ERROR                        _U("ELj013")	/*! 检测到SQLite数据库错误\n[No.:%d-->%s]*/
#define	UGS_ODBC_ERROR                          _U("ELj014")	/*! ODBC错误:%s*/
#define	UGS_DATASOURCE_S                        _U("ELj015")	/*! %s*/
#define	UGS_DATASOURCE_D                        _U("ELj016")	/*! %d*/
#define	UGS_DATABASE_TYPE_INVALID               _U("ELj017")	/*! 非法的数据库类型*/

//值域相关的的错误信息
#define	UGS_DOMAIN_DATATYPE_NOT_MATCH           _U("EOa001")	/*!写入值类型和值域信息类型不匹配 */
#define	UGS_DOMAIN_FIELD_VALUE_INVALID          _U("EOa002")	/*!字段值非法，不在值域内 */
#define UGS_DOMAIN_NAME_ALREAD_USED			    _U("EOa003")    /*!域的名称已经被使用*/
#define UGS_DOMAIN_FIELDTYPE_NOT_SUPPORT		_U("EOa004")    /*!域不支持的字段类型*/
#define UGS_DOMAIN_NOT_EXIST					_U("EOa005")    /*!指定的域不存在*/
#define UGS_DOMAIN_DATASET_NULLORNOTVECTORY	    _U("EOa006")    /*!数据集指针为空或数据集不是矢量数据集*/
#define UGS_DOMAIN_TABLE_CREATE_FAILED	        _U("EOa007")    /*!值域表 %s 创建失败*/
#define UGS_DOMAIN_TRUNCATE_TABLE_FAILED	    _U("EOa008")    /*!清空值域表 %s 失败*/
#define UGS_DOMAIN_DELETEDOMAIN_FAILED			_U("EOa009")    /*!删除值域失败*/
#define UGS_DOMAIN_INSERT_RECORDSET_FAILED		_U("EOa010")    /*!值域 %s 表插入记录失败*/
#define UGS_DOMAIN_UPDATE_RECORDSET_FAILED		_U("EOa011")    /*!值域 %s 表更新记录失败*/
#define UGS_DOMAIN_CODE_TOBINARY_FAILED			_U("EOa012")    /*!CODE域信息转换二进制失败*/
#define UGS_DOMAIN_RANGE_TOBINARY_FAILED		_U("EOa013")    /*!RANGE域信息转换二进制失败*/
#define UGS_DOMAIN_USING						_U("EOa014")    /*!值域正在使用*/
#define UGS_DOMAIN_CREATE_RANGE_FAILED			_U("EOa015")    /*!构建范围域失败*/
#define UGS_DOMAIN_CREATE_CODE_FAILED			_U("EOa016")    /*!构建代码域失败*/


//空间处理建模的错误
#define	UGS_SPM_FILE_NOT_EXIST                   _U("ENa001")	/*! _U("%s")文件不存在*/
#define	UGS_SPM_XML_NODE_MUSTHASCHILD            _U("ENa002")	/*! _U("%s")结点应有子结点*/
#define	UGS_SPM_XML_NODE_FINDBYATTRIBUTE_FAIL    _U("ENa003")	/*! 未能找到属性_U("%s")为_U("%s")的_U("%s")结点*/
#define	UGS_SPM_DATAEXCHANGE_ATTACHDATASOURCE_FAIL    _U("ENa004")	/*! 给DataExchange设定数据源_U("%s")失败*/
#define	UGS_SPM_DATAEXCHANGE_IMPORT_FAIL		 _U("ENa005")	/*! 导入数据_U("%s")失败*/
#define	UGS_SPM_DATASET_ISREGION                 _U("ENa006")	/*! _U("%s")数据集类型必须是面数据集*/
#define	UGS_SPM_OBJ_FAILNEW                      _U("ENa007")	/*! 创建_U("%s")对象失败*/
#define	UGS_SPM_XML_GETDOCUMENT_FAIL             _U("ENa008")	/*! 获取XML文件_U("%s")的Document结点失败*/
#define	UGS_SPM_CLASSFUNCTION_FAIL               _U("ENa009")	/*! _U("%s")类的_U("%s")方法失败*/
#define	UGS_SPM_RECORDSET_ID_PROPERTY_INVALID    _U("ENa010")	/*! ID为_U("%d")的记录的_U("%s")为空或者非法*/
#define	UGS_SPM_FILE_NOT_WRITEABLE				 _U("ENa011")	/*! _U("%s") 不可写*/
#define	UGS_SPM_PROJECTION_FIND_FAIL			 _U("ENa012")	/*! 查找 _U("%s") 的投影失败*/
#define	UGS_SPM_PROJECTION_CREATE_FAIL			 _U("ENa013")	/*! 创建外部投影文件 _U("%s") 失败*/
#define	UGS_SPM_DATASET_OPEN_FAILED              _U("ENa014")	/*! 打开数据集[%s]失败*/
#define	UGS_SPM_FILE_OPEN_FAILED              _U("ENa015")	/*! 打开文件[%s]失败*/
#define	UGS_SPM_DEST_PROJECTION_CREATE_FAILED              _U("ENa016")	/*! 创建目标影像投影失败*/
#define	UGS_SPM_PARAMS_INVALID              _U("ENa017")	/*! 参数设置错误*/
#define	UGS_SPM_NAME_INVALID              _U("ENa018")	/*! 名称[%s]错误*/
#define	UGS_SPM_CACHESIZE_INVALID              _U("ENa019")	/*! 缓存大小*/
#define	UGS_SPM_CREATE_FOLDER_FAILED              _U("ENa020")	/*! 创建文件[%s]夹失败*/
#define	UGS_SPM_SERCH_FILES_FAILED              _U("ENa021")	/*! 查找文件失败*/
#define	UGS_SPM_CREATE_METADATAUDB_FAILED              _U("ENa022")	/*! 根据影像创建元数据失败*/
#define	UGS_SPM_CREATE_THEME_FAILED              _U("ENa023")	/*! 创建元数据专题地图失败*/
#define	UGS_SPM_INIT_XMLPLATFORM_FAILED              _U("ENa024")	/*! 初始化XMLPlatform失败*/
#define	UGS_SPM_CREATE_DOMPARSER_FAILED              _U("ENa025")	/*! 创建XercesDOMParser失败*/
#define	UGS_SPM_QUERY_FAILED              _U("ENa026")	/*! 查询记录集失败%s*/
#define	UGS_SPM_GETBOUNDS_FAILED              _U("ENa027")	/*! 获取影像范围失败%s*/
#define	UGS_SPM_EXCEPTION              _U("ENa028")	/*! 异常：%s*/



// 基础信息
#define	UGS_COMPANY                             _U("IMa001")	/*! 北京超图软件股份有限公司*/
#define	UGS_UGC_VERSION                         _U("IMa002")	/*! SuperMap UGC 6.0*/
#define	UGS_CLASSLIB_NAME                       _U("IMa003")	/*! SuperMap 跨平台核心类库 (UGC)*/
#define	UGS_COPYRIGHT                           _U("IMa004")	/*! 版权所有(C) 2007-2009 北京超图软件股份有限公司，保留所有权利\n"*/
#define	UGS_CURRENT_TIME                        _U("IMa005")	/*! %Y年%m月%d日  %H时%M分%S秒*/
#define	UGS_ERROR_CODE                          _U("IMa006")	/*! SuperMap UGC类库错误代码: %d。*/
#define	UGS_WORK_ENVIRONMENT_INFO               _U("IMa007")	/*! 用户: %s 计算机: %s 时间: %s 操作系统: %s 硬件环境: %s 语言环境: %s 可用物理内存: %dkb 可用页面文件或虚拟内存: %dkb */
#define	UGS_SM_REGISTER_RUNTIME_PLEASE          _U("IMa008")	/*! 警告：您的运行版本没有注册 请调用 %s注册运行版*/
#define	UG_ERROROBJ_OUTPUT_FORMAT_DEBUG         _U("IMa009")	/*! 错误编号: %ERRORCODE\t 错误信息: %ERRORMSG\t 代码文件: %CODEFILE\t 代码行: %CODELINE\t 线程ID: %THREADID*/
#define	UG_ERROROBJ_OUTPUT_FORMAT               _U("IMa010")	/*! 错误编号: %ERRORCODE\t 错误信息: %ERRORMSG\t 线程ID: %THREADID*/
#define	UGS_S                                   _U("IMa011")	/*! %s*/
#define	UGS_THE_CURRENT_VERSION_OF_PLUGIN_IS_LATEST _U("IMa012")	/*! 当前插件已经是最新版本*/
#define	UGS_SHOULD_CLOSE_DATASET_BEFORE_CREATE_INDEX _U("IMa013")	/*! 建索引前必须关闭数据集*/
#define	UGS_SHOULD_CLOSE_DATASET_BEFORE_DELETE_INDEX _U("IMa014")	/*! 删除索引前必须关闭数据集*/
#define	UGS_DATASOURCE_COPYING_DATASET          _U("IMa015")	/*! 数据源{%s}复制数据集{%s}*/

// 进程信息
#define	UGS_BUILDING_SPATIAL_INDEX              _U("IMb001")	/*! 正在建立索引......*/
#define	UGS_PREPARING                           _U("IMb002")	/*! 正在准备...*/
#define	UGS_BEGIN_IMPORTING_DATA                _U("IMb003")	/*! 开始导入数据..*/
#define	UGS_ALREADY_IMPORT_D_OBJECT             _U("IMb004")	/*! 已经导入%ld个对象*/
#define	UGS_IMORTING_THE_SINGLE_BAND_D          _U("IMb005")	/*! 正在导入单波段数据(%d)...*/
#define	UGS_IMPROTING_DATAFILE_S                _U("IMb006")	/*! 正在导入数据文件：%s ...*/
#define	UGS_IMPORTING_THE_D_BAND                _U("IMb007")	/*! 正在导入第 %d 个波段...*/
#define	UGS_EXPORTING_DATAFILE_S                _U("IMb008")	/*! 正在导出数据文件：%s*/
#define	UGS_FINISH_IMPORT_THE_SINGLE_BAND       _U("IMb009")	/*! 完成单波段数据导入*/
#define	UGS_FINISH_IMPORT_THE_D_BAND            _U("IMb010")	/*! 完成第 %d 个波段导入*/
#define	UGS_OPENING_DATASOURCE                  _U("IMb011")	/*! 正在打开数据源...*/
#define	UGS_IS_CREATING_PYRAMID                 _U("IMb012")	/*! 正在创建影像金字塔...*/
#define	UGS_HAS_IMPORTED_D_SCANLINE             _U("IMb013")	/*! 已处理了%d条扫描线*/
#define	UGS_D_D_SCANLINE                        _U("IMb014")	/*! 正在处理[%d/%d]...*/
#define	UGS_IS_EDITING                          _U("IMb015")	/*! 正在编辑*/
#define	UGS_IS_RECONCILE                        _U("IMb016")	/*! 正在协调*/
#define	UGS_RASTER_PRODUCE                      _U("IMb017")	/*! 栅格数据预处理..*/
#define	UGS_IS_PRODUCING_D                      _U("IMb018")	/*! 第%d层处理中...*/
#define	UGS_IS_PRODUCING_MODEL_INFO             _U("IMb019")	/*! 正在处理模型信息...*/
#define	UGS_IS_PRODUCING_MODEL_DATA             _U("IMb020")	/*! 模型数据预处理...*/
#define	UGS_IS_PRODUCING_MODEL_CACHE            _U("IMb021")	/*! 模型缓存生成中...*/
#define	UGS_IS_IMPORTING_FILE                   _U("IMb022")	/*! 正在导入文件...*/
#define	UGS_FAILED_TO_TRANS_SCANLINE            _U("IMb023")	/*! 转换%d扫描线失败...*/
#define	UGS_FAILED_TO_SET_SCANLINE_D            _U("IMb024")	/*! 设置%d扫描线失败...*/
#define	UGS_FAILED_TO_READ_SCANLINE_D           _U("IMb025")	/*! 读取%d扫描线失败...*/
#define	UGS_FAILED_TO_SAVE_SCANLINE_D           _U("IMb026")	/*! 保存%d扫描线失败...*/
#define	UGS_SUCCESSED_TO_READ_SCANLINE_D        _U("IMb027")	/*! 读取%d扫描线成功*/
#define	UGS_FAILED_TO_WRITE_SCANLINE_D          _U("IMb028")	/*! 写入%d扫描线失败*/
#define	UGS_HAS_PRODUCED_D_SCANLINE             _U("IMb029")	/*! 已处理第%d波段的第%d条扫描线...*/
#define	UGS_CANCLE                              _U("IMb030")	/*! 用户取消了此次操作*/
#define	UGS_FAILED_TO_SET_BLOCK_D               _U("IMb031")	/*! 设置%d行,%d列栅格块失败*/
#define	UGS_FAILED_TO_SAVE_BLOCK_D              _U("IMb032")	/*! 保存%d行,%d列栅格块失败*/
#define	UGS_HAS_PRODUCED_D_BLOCK                _U("IMb033")	/*! 已处理[%d/%d]个栅格块...*/
#define	UGS_SUCCESSED_TO_READ_BLOCK_D           _U("IMb034")	/*! 读取%d, %d瓦片成功*/
#define	UGS_FAILED_TO_WRITE_BLOCK_D             _U("IMb035")	/*! 写入%d, %d瓦片失败*/
#define	UGS_FAILED_TO_READ_BLOCK_D              _U("IMb036")	/*! 读取%d, %d瓦片失败*/
#define	UGS_IS_ADDING_RECORD_TO_DATASET         _U("IMb037")	/*! 正往数据集里添加记录...*/
#define	UGS_FAILED_TO_READ_D_POINT              _U("IMb038")	/*! 读取第%d个Point几何对象时失败！*/
#define	UGS_FAILED_TO_READ_D_POINTZ             _U("IMb039")	/*! 读取第%d个PointZ几何对象时失败！*/
#define	UGS_FAILED_TO_READ_D_MULTIPOINT         _U("IMb040")	/*! 读取第%d个MultiPoint几何对象时失败！*/
#define	UGS_FAILED_TO_READ_D_LINE               _U("IMb041")	/*! 读取第%d个Line几何对象时失败！*/
#define	UGS_FAILED_TO_READ_D_LINEZ              _U("IMb042")	/*! 读取第%d个LineZ几何对象时失败！*/
#define	UGS_FAILED_TO_READ_D_LINEM              _U("IMb043")	/*! 读取第%d个LineM几何对象时失败！*/
#define	UGS_FAILED_TO_READ_D_REGION             _U("IMb044")	/*! 读取第%d个Region几何对象时失败！*/
#define	UGS_FAILED_TO_READ_D_REGIONZ            _U("IMb045")	/*! 读取第%d个RegionZ几何对象时失败！*/
#define	UGS_FAILED_TO_CREATE_D_POINT            _U("IMb046")	/*! 创建第%d个Point几何对象时失败！*/
#define	UGS_FAILED_TO_CREATE_D_POINTZ           _U("IMb047")	/*! 创建第%d个PointZ几何对象时失败！*/
#define	UGS_FAILED_TO_CREATE_D_MULTIPOINT       _U("IMb048")	/*! 创建第%d个MultiPoint几何对象时失败！*/
#define	UGS_FAILED_TO_CREATE_D_LINE             _U("IMb049")	/*! 创建第%d个Line几何对象时失败！*/
#define	UGS_FAILED_TO_CREATE_D_LINEZ            _U("IMb050")	/*! 创建第%d个LineZ几何对象时失败！*/
#define	UGS_FAILED_TO_CREATE_D_LINEM            _U("IMb051")	/*! 创建第%d个LineM几何对象时失败！*/
#define	UGS_FAILED_TO_CREATE_D_REGION           _U("IMb052")	/*! 创建第%d个Region几何对象时失败！*/
#define	UGS_FAILED_TO_CREATE_D_REGIONZ          _U("IMb053")	/*! 创建第%d个RegionZ几何对象时失败！*/
#define	UGS_IMAGE_SIZE_DD                       _U("IMb054")	/*! 图像大小是%d*%d*/
#define	UGS_IMAGE_HAS_D_BANDS                   _U("IMb055")	/*! 图像有%ld个波段*/
#define	UGS_BLOCK_SIZE_IS_DD                    _U("IMb056")	/*! 图像是个瓦片数据，瓦片大小是：%d*%d*/
#define	UGS_IMAGE_HAS_D_SCANLINES               _U("IMb057")	/*! 图像有%d条strip*/
#define	UGS_SCANLINE_SIZE_IS_D                  _U("IMb058")	/*! 条带大小为%d*/
#define	UGS_SCANLINE_HAS_D_ROW                  _U("IMb059")	/*! 每个条带包括%d行*/
#define	UGS_IMAGE_BITS_IS_D                     _U("IMb060")	/*! 图像位深是%ld*/
#define	UGS_IMAGE_WIDTH_IS_D                    _U("IMb061")	/*! 图像宽：%d*/
#define	UGS_IMAGE_HEIGHT_IS_D                   _U("IMb062")	/*! 图像高：%d*/
#define	UGS_NOT_SUPPORT_THE_S_PIXEL_FORMAT      _U("IMb063")	/*! 不支持的像素格式:%d*/
#define	UGS_HAS_DD_ELEMENT                      _U("IMb064")	/*! 一共%d个%d要素*/
#define	UGS_NETWORK_TOTAL_COST_LF               _U("IMb065")	/*! 网络分析总的花费是：%lf。*/
#define	UGS_COST_UNIT                           _U("IMb066")	/*! 个耗费单位*/
#define	UGS_DRIVE_GUIDE                         _U("IMb067")	/*! 第[**%d**]个行驶导引：*/
#define	UGS_START_POINT                         _U("IMb068")	/*! 起始点*/
#define	UGS_START_POINT_S                       _U("IMb069")	/*! 起始点[%s]*/
#define	UGS_ANONYMITY_ROUTE                     _U("IMb070")	/*! 匿名路段*/
#define	UGS_START_FROM_S                        _U("IMb071")	/*! 从%s出发*/
#define	UGS_ARRIVE_END_POINT                    _U("IMb072")	/*! 到达终点。*/
#define	UGS_ARRIVE_END_POINT_S                  _U("IMb073")	/*! 到达终点[%s]*/
#define	UGS_ARRIVE_END_POINT_SS                 _U("IMb074")	/*! 到达终点。 终点在[%s]%s。*/
#define	UGS_ARRIVE_END_POINT_SSS                _U("IMb075")	/*! 到达终点[%s]。 终点在[%s]%s。*/
#define	UGS_ROUTE_POINT_D                       _U("IMb076")	/*! %d号路由点*/
#define	UGS_ROUTE_POINT_D_S                     _U("IMb077")	/*! %d号路由点 %s*/
#define	UGS_ARRIVE_S                            _U("IMb078")	/*! 到达[%s]*/
#define	UGS_ARRIVE_S_IN_ROUTE_S                 _U("IMb079")	/*! 到达[%s],在道路%s*/
#define	UGS_COST_UNIT_LF                        _U("IMb080")	/*! 花费单位： %lf*/
#define	UGS_NETWORK_ARC_LENGTH_LF               _U("IMb081")	/*! 网络弧段长度：%lf*/
#define	UGS_UNKNOW_REMAIN_TIME                  _U("IMb082")	/*! 无法计算剩余时间*/
#define	UGS_COUMPUTE_DISTANCE                   _U("IMb083")	/*! 距离计算中...*/
#define	UGS_BUILDTOPOGRID                       _U("IMb084")	/*! 正在建立网格索引...*/
#define	UGS_COMPUTEMAXDISTANCE                  _U("IMb085")	/*! 正在计算最大距离...*/
#define	UGS_GETALLGEOMETRY                      _U("IMb086")	/*! 获取几何对象中...*/
#define	UGS_GETPACKAGEPNTS                      _U("IMb087")	/*! 正在计算凸包边界...*/
#define	UGS_COMPUTEWITHLESSGEOS                 _U("IMb088")	/*! 正在计算小规模距离...*/
#define	UGS_SAVEATTRIBUTE                       _U("IMb089")	/*! 正在保存属性表...*/
#define	UGS_GETGEOSANDATTS                      _U("IMb090")	/*! 正在读取信息...*/
#define	UGS_POINTASTAG                          _U("IMb091")	/*! 正在建立映射关系...*/
#define	UGS_UPDATEFIELDS                        _U("IMb092")	/*! 属性更新中...*/
#define	UGS_CREATING_GRID                       _U("IMb093")	/*! 正在创建网格...*/
#define	UGS_PRODUCING_LINE_DATASET              _U("IMb094")	/*! 线数据集处理中...*/
#define	UGS_ISMULTITHREADING                    _U("IMb095")	/*! 执行多线程*/
#define	UGS_ISSINGLETHREADING                   _U("IMb096")	/*! 执行单线程*/
#define	UGS_FINISH_PREPARED_DATA                _U("IMb097")	/*! 数据准备完毕*/
#define	UGS_PRODUCING_FILE_DIRECTORY            _U("IMb098")	/*! 处理文件/文件夹：%s*/
#define	UGS_FINDFILEEXTPATHS_CURRENT            _U("IMb099")	/*! 在当前目录下搜索完毕*/
#define	UGS_FINDFILEEXTPATHS_SUBDIR             _U("IMb100")	/*! 在子目录中搜索完毕*/
#define	UGS_CAL_SEP                             _U("IMb101")	/*! 开始计算进度*/
#define	UGS_HAS_PRODUCED_D_FEATURE              _U("IMb102")	/*! 已处理[%d/%d]个要素...*/
#define	UGS_FINISH                              _U("IMb103")	/*! 处理完毕*/
#define	UGS_IS_CREATING_MAPCACHE                _U("IMb104")	/*! 正在生成地图缓存[%s]*/
#define	UGS_BUILD_MAPCACHE_STATUS               _U("IMb105")	/*! 已完成了%d缓存出图*/
#define	UGS_LOADING_3D_SCENE                    _U("IMb106")	/*! 三维场景加载...*/
#define	UGS_LOADING_ELEMENT_OF_3D_SCENE         _U("IMb107")	/*! 加载场景元素...*/
#define	UGS_LOADING_LAYER_D                     _U("IMb108")	/*! 加载第%d个普通图层...*/
#define	UGS_LOADING_TERRAIN_LAYER_D             _U("IMb109")	/*! 加载第%d个地形图层...*/
#define	UGS_LOAD_3D_SCENE_SUCCESS               _U("IMb110")	/*! 场景加载完毕！*/
#define	UGS_VECTOR_PRODUCE                      _U("IMb111")	/*! 矢量数据预处理..*/
#define	UGS_IS_PRODUCING_VECTOR_INFO            _U("IMb112")	/*! 正在处理矢量信息...*/
#define	UGS_IS_PRODUCING_VECTOR_DATA            _U("IMb113")	/*! 矢量数据预处理...*/
#define	UGS_IS_PRODUCING_VECTOR_CACHE           _U("IMb114")	/*! 矢量缓存生成中...*/
#define	UGS_IS_CREATING_3DCACHE                 _U("IMb115")	/*! 生成三维缓存[%s]*/
#define	UGS_BUILD_3DCACHE_STATUS                _U("IMb117")	/*! 生成第%d层，剩余%d层，图片%d/%d*/
#define	UGS_BUILD_3DCACHE_STATUS_LAST           _U("IMb118")	/*! 生成第%d层，这是最后一层，图片%d/%d*/
#define	UGS_BUILD_2DCACHE_STATUS                _U("IMb119")	/*! 生成1:%s的缓存，剩余%d个比例尺，图片%lld/%lld */
#define	UGS_BUILD_2DCACHE_STATUS_LAST           _U("IMb120")	/*! 生成1:%s的缓存，这是最后一个比例尺，图片%lld/%lld */
#define	UGS_BUILD_3DTERRAIN_CACHE_STATUS        _U("IMb121")	/*! 正在生成第 %d 层缓存，剩余 %d 层缓存\n该层一共有 %d 块地形需要生成，正在生成第 %d 块地形*/
#define	UGS_BUILD_3DTERRAIN_CACHE_STATUS_LAST   _U("IMb122")	/*! 正在生成第 %d 层缓存，这是最后一层缓存\n该层下一共有 %d 块地形需要生成，正在生成第 %d 块地形*/
#define	UGS_SPATIALREF_CONVERTING               _U("IMb123")	/*! 正在进行投影转换*/
#define	UGS_PERCENT_HAVE_DONE                   _U("IMb124")	/*! 已完成 %d%%*/
#define	UGS_MASTER_DATASET_SPATIALREF_CONVERTING _U("IMb125")	/*! 正在对主数据集进行投影转换*/
#define	UGS_SUB_DATASET_SPATIALREF_CONVERTING   _U("IMb126")	/*! 正在对子数据集进行投影转换*/
#define	UGS_VIEWSHED_SCAN                       _U("IMb127")	/*! 正在扫描可视域*/
#define	UGS_VIEWSHED_SCAN_NUM                   _U("IMb128")	/*! 正在扫描可视域[%d/%d]*/
#define	UGS_INTERPOLATE_SKRIG_NUM               _U("IMb129")	/*! 正在进行简单克里金插值[%d/%d]...*/
#define	UGS_INTERPOLATE_OKRIG_NUM               _U("IMb130")	/*! 正在进行普通克里金插值[%d/%d]...*/
#define	UGS_INTERPOLATE_UKRIG_NUM               _U("IMb131")	/*! 正在进行泛克里金插值[%d/%d]...*/
#define	UGS_INTERPOLATE_INITIAL                 _U("IMb132")	/*! 插值初始化...*/
#define	UGS_INTERPOLATE_IDW_NUM                 _U("IMb133")	/*! 正在进行IDW插值[%d/%d]...*/
#define	UGS_INTERPOLATE_RBF_NUM                 _U("IMb134")	/*! 正在进行RBF插值[%d/%d]...*/
#define	UGS_VIEWSHED_SCAN_VIEWPOINT_NUM         _U("IMb135")	/*! 正在扫描第[%d/%d]个观测点的可视域...*/
#define	UGS_CONTOUR_TRACK_NUM					_U("IMb136")	/*! 正在追踪第[%d/%d]条等值线...*/
#define	UGS_ISOPOINT_TRACK_NUM                  _U("IMb137")	/*! 正在追踪等值点...*/
#define	UGS_INTERPOLATE_TEMP                    _U("IMb138")	/*! 正在生成中间插值结果...*/
#define	UGS_CLEARING_REPEATE_LINESEGS           _U("IMb139")	/*! 清除重复线段...*/
#define	UGS_STEP_1_CLEAN_REPEATE_LINESEGS       _U("IMb140")	/*! 清除重复线段预处理[%d/%d]...*/
#define	UGS_STEP_2_CLEAN_REPEATE_LINESEGS       _U("IMb141")	/*! 清除重复线段[%d/%d]...*/
#define	UGS_CLEARING_REPEATE_LINES              _U("IMb139")	/*! 清除重复线...*/
#define	UGS_STEP_1_CLEAN_REPEATE_LINES          _U("IMb140")	/*! 清除重复线预处理[%d/%d]...*/
#define	UGS_STEP_2_CLEAN_REPEATE_LINES          _U("IMb141")	/*! 清除重复线[%d/%d]...*/
#define	UGS_EXTENDING_DANGLE_LINES              _U("IMb142")	/*! 延伸长悬线...*/
#define	UGS_STEP_1_EXTENDING_LONG_DANGLE_LINE   _U("IMb143")	/*! 延伸长悬线[%d/%d]...*/
#define	UGS_STEP_2_EXTENDING_LONG_DANGLE_LINE   _U("IMb144")	/*! 延伸长悬线[%d/%d]...*/
#define UGS_INTERSECTING                        _U("IMb145")	/*! 弧段求交...*/
#define UGS_STEP_3_INTERSECT_ALL_LINES          _U("IMb146")	/*! 线分割运算[%d/%d]...*/
#define	UGS_CLEARING_SMALL_DANGLE               _U("IMb147")	/*! 清除短悬线...*/
#define UGS_STEP_1_CLEAN_SMALL_DANGLE_LINE      _U("IMb148")	/*! 检查并去除短悬线[%d/%d]...*/
#define UGS_MERGING_CLOSE_NODE                  _U("IMb149")	/*! 合并临近端点...*/
#define UGS_STEP_2_MERGE_CLOSE_NODE             _U("IMb140")	/*! 结点合并...*/
#define UGS_STEP_1_MERGE_CLOSE_NODE             _U("IMb151")	/*! 处理弧段结点[%d/%d]...*/
#define UGS_BUILDING_NETWORK                    _U("IMb152")	/*! 正在创建网络拓扑关系...*/
#define UGS_STEP_1_BUILDING                     _U("IMb153")   	/*! 创建多边形[%d/%d]...*/
#define UGS_STEP_2_BUILDING                     _U("IMb154")   	/*! 多边形预处理[%d/%d]...*/
#define UGS_STEP_3_BUILDING                     _U("IMb155")   	/*! 岛多边形处理[%d/%d]...*/
#define UGS_STEP_4_BUILDING                     _U("IMb156")   	/*! 整理多边形图层[%d/%d]...*/
#define UGS_BUILDING_POLYGONS                   _U("IMb157")   	/*! 整理多边形图层...*/
#define UGS_CLIP_CAD                            _U("IMb158")   	/*! 正在裁剪CAD...*/
#define UGS_CLIP_TEXT                           _U("IMb159")   	/*! 正在裁剪文本...*/
#define UGS_MERGING_DATASET_DISSOLVE            _U("IMb160")   	/*! 数据集融合...*/
#define UGS_TOPO_UNION_DISSOLVING               _U("IMb161")   	/*! 正在合并字段值相同的对象...*/
#define UGS_MAKE_TOPO_POLYLINE                  _U("IMb162")   	/*! 提取拓扑线...*/
#define UGS_POLYLINE_PREPROCESS                 _U("IMb163")   	/*! 线预处理...*/
#define UGS_CLIP_RASTER                         _U("IMb164")  	/*! 栅格裁剪...*/
#define UGS_CLIP_RASTER_NUM                     _U("IMb165")  	/*! 正在裁剪[%d/%d]...*/
#define UGS_DATASOURCE_COMPACT					_U("IMb166")	/*! 正在紧缩数据源...*/
#define UGS_DATASOURCE_COMPACT_DATASET_NUM		_U("IMb167")	/*!	正在处理数据集[%d/%d]...*/
#define UGS_IMPORTING_THE_D_BAND_SAVING			_U("IMb168")	/*!	第[%d/%d]波段导入成功，正在保存...*/
#define UGS_IMPORT_PARTSUC_GOONING		        _U("IMb169")	/*!	导入已完成第%d个(共%d个)!*/
#define UGS_EXPORT_PARTSUC_GOONING		        _U("IMb170")	/*!	导出已完成第%d个(共%d个)!*/
#define UGS_RASTER_MOSAIC						_U("IMb171")	/*! 栅格镶嵌...*/
#define UGS_RASTER_CONVERT_TO_VECTOR			_U("IMb172")	/*! 栅格转矢量...*/
#define UGS_VECTOR_CONVERT_TO_RASTER			_U("IMb173")	/*! 矢量转栅格...*/
#define UGS_RASTER_THIN							_U("IMb174")	/*! 栅格细化...*/
#define UGS_RASTER_MATH_ANALYSE					_U("IMb175")	/*! 栅格代数运算...*/
#define UGS_CREATING_TARGET_DATASET				_U("IMb176")	/*! 正在创建结果数据集...*/
#define UGS_CALCULATE_ORTHO_IMAGE				_U("IMb177")	/*! 计算正射三维影像...*/
#define UGS_CALCULATE_CUT_FILL					_U("IMb178")	/*! 填挖方计算...*/
#define UGS_INTERPOLATING						_U("IMb179")	/*! 插值计算...*/
#define UGS_RASTER_RESAMPLE						_U("IMb180")	/*! 栅格重采样...*/
#define UGS_GRID_RECLASS						_U("IMb181")	/*! 栅格重分级...*/
#define UGS_EXTRACT_ISO_LINE					_U("IMb182")	/*! 提取等值线...*/
#define UGS_EXTRACT_ISO_REGION					_U("IMb183")	/*! 提取等值面...*/
#define	UGS_ISOLINE_TEMP                        _U("IMb184")	/*! 正在提取中间等值线结果...*/
#define UGS_CALCULATE_SLOPE                     _U("IMb185")	/*! 生成坡度图...*/
#define UGS_CALCULATE_ASPECT                    _U("IMb186")	/*! 生成坡向图...*/
#define UGS_CALCULATE_HILLSHADE					_U("IMb187")	/*! 生成三维晕渲图...*/
#define UGS_FIND_EXTREMUM						_U("IMb188")	/*! 查找极值点...*/
#define UGS_ELIMINATE_SMALLPOLYGON				_U("IMb189")	/*! 碎多边形合并...*/
#define UGS_APPEND_FIELD_INFO					_U("IMb190")	/*!	正在追加字段...*/
#define UGS_CLIP_VECTOR                         _U("IMb191")  	/*! 矢量裁剪...*/
#define	UGS_IS_UPDATING_DATASET                 _U("IMb192")	/*! 正在进行栅格数据集更新...*/
#define UGS_GRID_MATCH							_U("IMb193")	/*! 地形模型匹配...*/
#define	UGS_CLEANING_REDUDANCE_VERTEXES         _U("IMb194")	/*! 去除冗余点...*/
#define	UGS_STEP_1_CLEANING_REDUDANCE_VERTEXES  _U("IMb195")	/*! 去除冗余点[%d/%d]...*/
#define UGS_MERGE_PSEUDO_NODE					_U("IMb196")	/*! 假结点合并...*/	
#define UGS_TOPO_PROCESSING			            _U("IMb197")	/*! 正在拓扑处理[%d/%d]...*/
#define	UGS_TOPO_CHECKING                       _U("IMb198")	/*! 正在拓扑检查[%d/%d]...*/
#define	UGS_TOPO_FIXING                         _U("IMb199")	/*! 正在拓扑修复[%d/%d]...*/
#define UGS_NODE_IDENTIFYING					_U("IMb200")	/*! 节点分类*/
#define UGS_STEP_1_NODE_IDENTIFYING				_U("IMb201")	/*! 处理弧段结点[%d/%d]...*/
#define UGS_STEP_2_NODE_IDENTIFYING				_U("IMb202")	/*! 创建结点索引文件[%d/%d]...*/
#define UGS_STEP_1_LINE_NET_BUILD				_U("IMb203")	/*! 创建结点图层[%d/%d]...*/
#define UGS_STEP_2_LINE_NET_BUILD				_U("IMb204")	/*! 弧段结点编码[%d/%d]...*/
#define UGS_STEP_3_LINE_NET_BUILD				_U("IMb205")	/*! 创建网络图层[%d/%d]...*/
#define UGS_IN_PROCESS_OF_BUILDPYRAMID          _U("IMb206")    /*! 正在为波段%d创建金字塔...*/
#define UGS_CALCULATE_COST_DISTANCE				_U("IMb207")	/*! 正在计算耗费距离栅格...*/
#define UGS_CALCULATE_STRAIGHT_DISTANCE			_U("IMb208")	/*! 正在计算直线距离栅格...*/
#define UGS_CALCULATE_COSTPATH					_U("IMb209")	/*! 耗费距离栅格最短路径分析...*/
#define UGS_CALCULATE_PTOP_PATHLINE				_U("IMb210")	/*! 计算两点间最优路径...*/
#define UGS_GRID_NEIBORHOOD_STATISTICS			_U("IMb211")	/*! 栅格邻域统计...*/
#define UGS_GRID_ZONAL_STATISTICS				_U("IMb212")	/*! 栅格分带统计...*/
#define UGS_GRID_REPLACE						_U("IMb213")	/*! 栅格数据查找替换...*/
#define UGS_RASTERCOLLECTION_SYNC				_U("IMb214")	/*! 正在同步栅格数据集集合...*/
#define UGS_GRID_COMMON_STATISTICS				_U("IMb215")	/*! 栅格常用统计...*/
#define UGS_GRID_BUILDLAKE						_U("IMb216")	/*! 地形挖湖...*/
#define UGS_GRID_CREATEDEM						_U("IMb217")	/*! 地形构建...*/
#define UGS_INTERPOLATE_TIN_NUM					_U("IMb218")	/*! 正在进行TIN插值[%d/%d]...*/
#define UGS_RASTER_SPLIT						_U("IMb219")	/*! 栅格切割...*/
#define	UGS_IS_CREATING_BASE_PYRAMID            _U("IMb220")	/*! 正在创建集合第一层金字塔...*/
#define UGS_BUILDING_ROUTE						_U("IMb221")	/*! 生成路由数据...*/
#define UGS_CREATE_ROUTE						_U("IMb222")	/*! 正在生成路由[%d/%d]...*/
#define UGS_CREATE_ROUTE_ONLY_PERCENT			_U("IMb223")	/*! 正在生成路由[%d %%]...*/
#define UGS_CALIBRATE_ROUTE						_U("IMb224")	/*! 正在校准路由数据...*/
#define UGS_TRAVERSE_ROUTE						_U("IMb225")	/*! 正在遍历路由数据[%d/%d]...*/
#define UGS_TRAVERSE_POINT						_U("IMb226")	/*! 正在遍历校准点数据[%d/%d]...*/
#define UGS_RESULT_ROUTE						_U("IMb227")	/*! 正在生成结果数据[%d/%d]...*/
#define UGS_BUILDING_EVENT_TABLE				_U("IMb228")	/*! 生成事件表...*/
#define UGS_CREATE_EVENT_TABLE					_U("IMb229")	/*! 正在生成事件表[%d/%d]...*/
#define UGS_BUILDING_GEOMETRY					_U("IMb230")	/*! 生成空间数据...*/
#define UGS_TRAVERSE_EVENT_TABLE				_U("IMb231")	/*! 正在遍历事件表数据[%d/%d]...*/
#define UGS_OVERLAY_EVENT						_U("IMb232")	/*! 正在叠加事件表...*/
#define UGS_CREATE_RESULT_EVENT					_U("IMb233")	/*! 正在生成结果事件表...*/
#define UGS_DISSOLVE_EVENT						_U("IMb234")	/*! 正在融合事件表...*/
#define	UGS_IS_COPYING_TEXTURE					_U("IMb235")	/*! 正在复制纹理...*/
#define UGS_CREATE_SEMAPHORE_FAILED             _U("IMb236")    /*! 创建信号量失败*/

// 地图单位信息
#define	UGS_SYMBOL_DEGREE                       _U("IMc001")	/*! °*/
#define	UGS_SYMBOL_MINUTE                       _U("IMc002")	/*! ˊ*/
#define	UGS_MILIMETER                           _U("IMc003")	/*! 毫米*/
#define	UGS_CENTIMETER                          _U("IMc004")	/*! 厘米*/
#define	UGS_DECIMETER                           _U("IMc005")	/*! 分米*/
#define	UGS_METER                               _U("IMc006")	/*! 米*/
#define	UGS_KILOMETER                           _U("IMc007")	/*! 千米*/
#define	UGS_MILE                                _U("IMc008")	/*! 英里*/
#define	UGS_INCH                                _U("IMc009")	/*! 英寸*/
#define	UGS_YARD                                _U("IMc010")	/*! 码*/
#define	UGS_FOOT                                _U("IMc011")	/*! 英尺*/
#define	UGS_DEGREE                              _U("IMc012")	/*! 度*/
#define	UGS_MINUTE                              _U("IMc013")	/*! 分*/
#define	UGS_SECOND                              _U("IMc014")	/*! 秒*/
#define	UGS_SQ_MILIMETER                        _U("IMc015")	/*! 平方毫米*/
#define	UGS_SQ_CENTIMETER                       _U("IMc016")	/*! 平方厘米*/
#define	UGS_SQ_DECIMETER                        _U("IMc017")	/*! 平方分米*/
#define	UGS_SQ_METER                            _U("IMc018")	/*! 平方米*/
#define	UGS_SQ_KILOMETER                        _U("IMc019")	/*! 平方公里*/
#define	UGS_SQ_MILE                             _U("IMc020")	/*! 平方英里*/
#define	UGS_SQ_INCH                             _U("IMc021")	/*! 平方英寸*/
#define	UGS_SQ_YARD                             _U("IMc022")	/*! 平方码*/
#define	UGS_SQ_FOOT                             _U("IMc023")	/*! 平方英尺*/
#define	UGS_SYMBOL_SECOND                       _U("IMc024")	/*! 〞*/
#define	UGS_SYMBOL_SUSPENSION_POINTS            _U("IMc025")	/*! …*/

// 动态库信息
#define	UGS_LOAD_S_SUCCESS                      _U("IMd001")	/*! 加载%s成功*/
#define	UGS_LOAD_SDX_DYNAMIC_LIB_D_SUCCESS_D_FAILED _U("IMd002")	/*! 加载SDX动态库完毕: %d 个成功，%d个失败"*/
#define	UGS_LOAD_SDX_S_SUCCESS                  _U("IMd003")	/*! 加载SDX（%s）成功*/
#define	UGS_UNINSTALL_S_SUCCESS                 _U("IMd004")	/*! 卸载%s成功*/
#define	UGS_FINISH_UNINSTALL_SDX                _U("IMd005")	/*! 卸载SDX成功*/
#define	UGS_BEGIN_LOADING_SDX_DYNAMAIC_LIB      _U("IMd006")	/*! 开始加载SDX动态库*/
#define	UGS_BEGIN_LOADING_SDX                   _U("IMd007")	/*! 开始加载SDX：*/
#define	UGS_BEGIN_UNINSTALL_SDX                 _U("IMd008")	/*! 开始卸载SDX*/
#define	UGS_S_BREAK                             _U("IMd009")	/*! %s 异常*/
#define	UGS_S_SUCCESS                           _U("IMd010")	/*! %s 成功*/

// 文件及数据相关信息
#define	UGS_SET_IMPORT_PARAM                    _U("IMe001")	/*! 设置导入参数*/
#define	UGS_READY_IMPORT_DATA_FILE_S            _U("IMe002")	/*! 准备导入数据文件：%s*/
#define	UGS_FINISH_IMPROT_RASTER                _U("IMe003")	/*! 完成导入栅格数据*/
#define	UGS_BEGIN_IMPORTING_RASTER              _U("IMe004")	/*! 开始导入栅格数据...*/
#define	UGS_IMPORT_DATA_SUCCESS                 _U("IMe005")	/*! 数据导入成功*/
#define	UGS_ORIGINAL_CACHEMASTERFILE_S_NOT_EXIST_OR_INVALID_BEGIN_CREATING_NEW_FILE _U("IMe006")	/*! 原CacheMasterFile： %s            不存在或者不合法,开始创建新文件...*/
#define	UGS_MEMORY_FILE_S_CREATE_SUCCESS        _U("IMe007")	/*! 缓存文件全 %s 生成成功*/
#define	UGS_MEMORY_FILE_FULLNAME_S              _U("IMe008")	/*! 缓存文件全名: %s*/
#define	UGS_DEAL_WITH_DATAFILE_S_SUCCESS        _U("IMe009")	/*! 处理数据文件:%s 成功*/
#define	UGS_GET_OBJECT_COUNT_FROM_FILE          _U("IMe010")	/*! 从文件中获取对象个数...*/
#define	UGS_GET_OBJECT_COUNT_FROM_FILE_D        _U("IMe011")	/*! 从文件中获取对象个数为：%d*/
#define	UGS_MSTERFILE_FULLNAME_S                _U("IMe012")	/*! MasterFile文件全名: %s*/
#define	UGS_CACHEMASTERFILE_S_CREATE_SUCCESS    _U("IMe013")	/*! CacheMasterFile： %s 创建成功*/
#define	UGS_IMPORTING_VECTOR_DATASET            _U("IMe014")	/*! 矢量数据追加*/
#define	UGS_CREATE_DATABASE_S                   _U("IMe015")	/*!  创建数据库：%s*/
#define	UGS_DATABASE_S_NOT_EXIST                _U("IMe016")	/*!  数据库：%s 不存在*/
#define	UGS_FINISH_ATTACHDATASOURCE             _U("IMe017")	/*! 打开/创建目标文件完毕*/
#define	UGS_DIR_NPOS                            _U("IMe018")	/*! 一共 %d 个文件夹，开始序号为：%d.*/
#define	UGS_FINDFILEEXTPATHS_RESULT             _U("IMe019")	/*! 从[%s]文件夹中找到以 [%s] 为后缀的文件%d个*/
#define	UGS_FINISH_FILESGROUPINGBYFOLDER        _U("IMe020")	/*! 文件查找分组完毕*/
#define	UGS_EXPORT_DATA_SUCCESS                 _U("IMe021")	/*! 数据导出成功*/
#define	UGS_CANCLE_TO_EXPORT                    _U("IMe022")	/*! 用户取消导出操作*/
#define	UGS_EXPORT_DATA_FAILED                  _U("IMe023")	/*! 数据导出失败*/
#define	UGS_DELETE_DIRECTORY_S_FAILED           _U("IMe024")	/*!  目录 %s 已存在，且设置强行覆盖，但删除失败！*/
#define	UGS_DELETE_FIELD_S_FAILED               _U("IMe025")	/*!  文件 %s 已存在，且设置强行覆盖，但删除失败！*/
#define	UGS_EXPORT_FIELD_S_CANCLE               _U("IMe026")	/*!  文件 %s 已存在，且未设置强行覆盖，取消导出操作！*/
#define	UGS_IMPORT_PARAMETER_USELESS            _U("IMe027")	/*!  验证导入参数：导入参数无效，不进行导入操作!*/
#define	UGS_IMPORT_FILE_DELETE_FAILED           _U("IMe028")	/*!  导入文件打开失败!*/
#define	UGS_CANCLE_TO_IMPORT                    _U("IMe029")	/*!  用户取消导入操作*/
#define	UGS_IMPORT_BY_MULTIBAND                 _U("IMe030")	/*!  将数据按照多波段形式导入数据集 %s*/
#define	UGS_PIXELFORMAT_UNKNOWN                 _U("IMe031")	/*!  未知的像素格式*/
#define	UGS_UNKNOWN_PIXEL_IMPORT_NONLICET       _U("IMe032")	/*!  此文件像素格式未知，不进行导入操作!*/
#define	UGS_DELETE_OLD_DATASET_OVERWRITE        _U("IMe033")	/*!  暴力覆盖，删除原同名数据集*/
#define	UGS_GRID_INFOS_SAVE_FAILED              _U("IMe034")	/*!  栅格数据集信息保存失败！*/
#define	UGS_ASSIGNMENT_OPERATORS_FAILED         _U("IMe035")	/*!  为第 %d 行 %d 列的Block分配空间失败！*/
#define	UGS_DATASETUNEXIST_CREAT                _U("IMe036")	/*!  要追加的目标数据集不存在,新建数据集进行导入*/
#define	UGS_FILE_EXIST_WITHOUTOVERWRITE         _U("IMe037")	/*!  文件 %s 已存在，且未设置强行覆盖，不能进行导出操作！,新建数据集进行导入*/
#define	UGS_UNLIKENESS_BLOCK_WIDTH_HEIGHT       _U("IMe038")	/*!  块宽高不相等！*/
#define	UGS_WITHOUT_SIZE_SETTING                _U("IMe039")	/*!  无对应影像块大小设置！*/
#define	UGS_LAYERNAME_IS_NULL                   _U("IMe040")	/*!  图层 %s 的用户自定义图层名为空，该图层不进行导入处理*/
#define	UGS_LAYERS_OF_IMPORT                    _U("IMe041")	/*!  共导入 %d 个数据层*/
#define	UGS_DATASET_TO_APPEND_UNEXIST           _U("IMe042")	/*!  没有找到要进行追加操作的数据集 %s*/
#define	UGS_PRJCOORDSYS_OF_DATASET_DIFFER       _U("IMe043")	/*!  第 %d 个数据集携带投影不一致，不能导出！*/
#define	UGS_IMPORT_WORKSPACE                    _U("IMe044")	/*!  导入Workspace*/
#define	UGS_GET_VECTOR_FAILED                   _U("IMe045")	/*!  获取数据矢量层失败!*/
#define	UGS_IMPORT_NOT_RUN                      _U("IMe046")	/*!  没有执行导入操作!*/
#define	UGS_CAD_JUST_ENCNONE                    _U("IMe047")	/*!  CAD数据只支持encNONE编码！*/
#define	UGS_APPEND_DATASET                      _U("IMe048")	/*!  追加数据集*/
#define	UGS_DATASETS_IS_EMPTY                   _U("IMe049")	/*! 数据集数组为空，没有可供导出的数据集！*/
#define	UGS_DATASETS_COORDINATE_FAILED          _U("IMe050")	/*! 数据集坐标参考检查失败，取消导出操作!*/
#define	UGS_DATASETS_ALL_HAVE_NO_PRJ            _U("IMe051")	/*! 数据集都没有投影*/
#define	UGS_RECORDS_ADD_TO_DATABASE             _U("IMe052")	/*! 已满3000条，向数据库里面添加\n*/
#define	UGS_APPEND_FINISH_COST_TIME             _U("IMe053")	/*! 追加完毕，耗时 %lf!\n*/
#define UGS_READ_ATTRIBUTE_FIELD_FAILTURE       _U("IMe054")    /*! 读取数据属性字段失败！*/
#define UGS_OPEN_STYLE_FILE_FAILTURE            _U("IMe055")    /*! 打开风格文件失败！*/
#define UGS_FETURE_FIELD_COUNT_INVALID          _U("IMe056")    /*! 记录字段总数错误！*/
#define	UGS_SEQUENCE_STARTVAL_BIG_MAXVAL        _U("IMe057")	/*! 序列的初始值不能大于最大值*/
#define	UGS_SEQUENCE_UDB_INCREMENT_MUSTONE      _U("IMe058")	/*! UDB的序列增长值只能为1*/



// 数据源相关信息
#define	UGS_SDX_CREATEDATASOURCE_SUCCESS        _U("IMf001")	/*! SDX CreateDataSource成功！*/
#define	UGS_DATASOURCE_OPEN_SUCCESS             _U("IMf002")	/*! 数据源打开成功*/
#define	UGS_OGRDIVER_IS_S                       _U("IMf003")	/*! OGRDriver 为 %s*/
#define	UGS_DATASET_TYPE                        _U("IMf004")	/*! 数据集类型*/
#define	UGS_OBJECT_COUNT                        _U("IMf005")	/*! 对象个数*/
#define	UGS_CHARACTER_CODING                    _U("IMf006")	/*! 字符编码方式*/
#define	UGS_DATASET_BOUNDS                      _U("IMf007")	/*! 数据集范围*/
#define	UGS_TOP                                 _U("IMf008")	/*! 上边界*/
#define	UGS_BOTTOM                              _U("IMf009")	/*! 下边界*/
#define	UGS_LEFT_BOUNDARY                       _U("IMf010")	/*! 左边界*/
#define	UGS_RIGHT_BOUNDARY                      _U("IMf011")	/*! 右边界*/
#define	UGS_CREATE_SPATIALREF                   _U("IMf012")	/*! 创建空间参考系*/
#define	UGS_CREATE_COLORTABLE                   _U("IMf013")	/*! 创建颜色表*/
#define	UGS_EDITBULKOPERATE                     _U("IMf014")	/*! 请设置批量更新标志*/
#define UGS_FME_LICENSE_NOT_EXIST               _U("IMf015")    /*! FME许可不存在*/
// 字段相关信息
#define	UGS_SMID_VALUE_IS_ZERO                  _U("IMg001")	/*! SMID 的值为0*/
#define	UGS_READ_S                              _U("IMg002")	/*! 读取：%s \n*/
#define	UGS_FIELD_NAME                          _U("IMg003")	/*! 字段名*/
#define	UGS_FIELD_VAULE                         _U("IMg004")	/*! 字段值*/

// 地图相关信息
#define	UGS_VIEW_MAP_BEGAIN                     _U("IMh001")	/*! 开始显示地图*/
#define	UGS_RESOLUTION                          _U("IMh002")	/*! 分辨率*/
#define	UGS_LEGEND                              _U("IMh003")	/*! 图   例*/
#define	UGS_MIDDLE                              _U("IMh004")	/*! 中*/
#define	UGS_PRINT                               _U("IMh005")	/*! 打印*/
#define	UGS_GEOGRAPHIC_COORDINATE_SYSTEM        _U("IMh006")	/*! 任意直角坐标系：坐标起点以        为原点起算。*/
#define	UGS_ELEVATION_SYSTEM_1M                 _U("IMh007")	/*! 独立高程系，等高距为1m。*/
#define	UGS_NATIONAL_BASIC_SCALE_MAP_PART1      _U("IMh008")	/*! GB/T 20257.1－2007国家基本比例尺地图图式  第1部分：*/
#define	UGS_MAP_500_1000_2000                   _U("IMh009")	/*! 1:500  1:1000  1:2000地形图图式*/
#define	UGS_MEASURE_IN_YEAR                     _U("IMh0010")	/*!         于     年测制。*/
#define	UGS_UNTITLED                            _U("IMh0011")	/*! Untitled*/
#define	UGS_STATE_BUREAU_OF_SURVEYING_AND_MAPPING _U("IMh0012")	/*! 国家测绘局*/
#define	UGS_SECRET_AND_PERENNIAL                _U("IMh0013")	/*! 秘密 ★ 长期*/
#define	UGS_APPENDIX                            _U("IMh0014")	/*! 附注：*/
#define	UGS_DISTRICT_ABBREVIATORY_MAP_AND_ADJACENCY_TABLE _U("IMh0018")	/*! 政区略图与邻接图表*/
#define	UGS_AERIAL_SURVEY_AND_DRAW              _U("IMh0019")	/*!     年  月航摄，    年  月调绘，*/
#define	UGS_MAKE_IN_YEAR                        _U("IMh0020")	/*!         于    年制作*/
#define	UGS_XIAN_COORDINATE_SYSTEM_1985_5M      _U("IMh0021")	/*! 1980西安坐标系，1985国家高程基准；等高距为5m*/
#define	UGS_NATIONAL_BASIC_SCALE_MAP_PART2      _U("IMh0022")	/*! GB/T 20257.2－2006    国家基本比例尺地图图式  第2部分：*/
#define	UGS_MAP_5000_10000                      _U("IMh0023")	/*! 1:5000  1:10000地形图图式*/
#define	UGS_SLOPE_RULER                         _U("IMh0024")	/*! 坡度尺*/
#define	UGS_MEASURE_TWO_CONTOURS                _U("IMh0025")	/*! 量相邻两条等高线时用*/
#define	UGS_MEASURE_SIX_CONTOURS                _U("IMh0026")	/*! 量相邻六条等高线时用*/
#define	UGS_ICM_IN_MAP_IS_DM_IN_REALWORLD       _U("IMh0027")	/*! 图上1cm相当于实地%dm*/
#define	UGS_CHINESE_PEOPLE_REPUBLIC_BASIC_SCALE_MAP _U("IMh0028")	/*! 中华人民共和国基本比例尺地形图*/
#define	UGS_XIAN_COORDINATE_SYSTEM_1985_10M     _U("IMh0029")	/*! 1980西安坐标系，1985国家高程基准；等高距为10m*/
#define	UGS_NATIONAL_BASIC_SCALE_MAP_PART3      _U("IMh0030")	/*! GB/T 20257.3－2006    国家基本比例尺地图图式  第3部分：*/
#define	UGS_MAP_25000_50000_100000              _U("IMh0031")	/*! 1:25 000 1:50 000  1:100 000地形图图式*/
#define	UGS_XIAN_COORDINATE_SYSTEM_1985         _U("IMh0032")	/*! 1980西安坐标系，1985国家高程基准。*/
#define	UGS_NATIONAL_BASIC_SCALE_MAP            _U("IMh0033")	/*! GB/T 20257.4－2007    国家基本比例尺地图样式*/
#define	UGS_MAP_25000_50000_100000_PART4        _U("IMh0034")	/*! 第4部分：1:250000  1:500000  1:1000000地形图样式。*/
#define	UGS_MAGNETIC_MERIDIAN                   _U("IMh0035")	/*! 磁子午线*/
#define	UGS_VERILY_MERIDIAN                     _U("IMh0036")	/*! 真子午线*/
#define	UGS_VERTICAL_ORDINATE                   _U("IMh0037")	/*! 坐标纵线*/
#define	UGS_ICM_IN_MAP_IS_2DOT5KM_IN_REALWORLD  _U("IMh0038")	/*! 图上1cm相当于实地2.5km*/
#define	UGS_ICM_IN_MAP_IS_5KM_IN_REALWORLD      _U("IMh0039")	/*! 图上1cm相当于实地5km*/
#define	UGS_EQUAL_ANGLE_CONIC_PROJECTION        _U("IMh0040")	/*! 等角圆锥投影*/
#define	UGS_INMILE_IN_MAP_IS_1DOT852KM_IN_REALWORLD _U("IMh0041")	/*! 图上1 n mile相当于1.852km*/
#define	UGS_ALTIMETER                           _U("IMh0042")	/*! 高 度 表(m)*/
#define	UGS_DEPTHGAUGE_M                        _U("IMh0043")	/*! 深 度 表(m)*/
#define	UGS_DEPTHGAUGE                          _U("IMh0044")	/*! 深  度  表*/
#define	UGS_NATIONAL_BASIC_SCALE_TERRAIN_MAP    _U("IMh0045")	/*! 国家基本比例尺地形图*/

#define	UGS_MAP_IS_OUTPUTINGTODATASETIAMGE    _U("IMh0046")	/*! 地图正在输出为Image数据集[%s]*/

// topo数据集相关信息，包括拓扑预处理、拓扑构建、拓扑规则
#define	UGS_TOPO_RULE_ALREADY_EXIST             _U("IMi001")	/*! Topo规则已经存在*/
#define	UGS_AREA_NO_OVERLAP                     _U("IMi002")	/*! 面内无重叠*/
#define	UGS_AREA_NO_GAPS                        _U("IMi003")	/*! 面内无缝隙*/
#define	UGS_AREA_NO_OVERLAP_WITH                _U("IMi004")	/*! 面与面无重叠*/
#define	UGS_AREA_COVERED_BY_AREA_CLASS          _U("IMi005")	/*! 面被多个面覆盖*/
#define	UGS_AREA_CONTAINED_BY_AREA              _U("IMi006")	/*! 面被面包含*/
#define	UGS_AREA_BOUNDARY_COVERED_BY_LINES      _U("IMi007")	/*! 面边界被多条线覆盖*/
#define	UGS_AREA_BOUNDARY_COVERED_BY_AREA_BOUNDARY _U("IMi008")	/*! 面边界被边界覆盖*/
#define	UGS_AREA_CONTAIN_POINT                  _U("IMi009")	/*! 面包含点*/
#define	UGS_AREA_NO_OVERLAP_ON_BOUNDARY         _U("IMi010")	/*! 面边界无交叠*/
#define	UGS_AREA_NO_SELF_INTERSECT              _U("IMi011")	/*! 面内无自相交*/
#define	UGS_LINE_NO_INTERSECTION                _U("IMi012")	/*! 线内无相交*/
#define	UGS_LINE_NO_OVERLAP                     _U("IMi013")	/*! 线内无重叠*/
#define	UGS_LINE_NO_DANGLES                     _U("IMi014")	/*! 线内无悬线*/
#define	UGS_LINE_NO_PSEUDONODES                 _U("IMi015")	/*! 线内无假结点*/
#define	UGS_LINE_NO_OVERLAP_WITH                _U("IMi016")	/*! 线与线无重叠*/
#define	UGS_LINE_NO_INTERSECT_OR_INTERIOR_TOUCH _U("IMi017")	/*! 线内无相交或无内部接触*/
#define	UGS_LINE_NO_SELF_OVERLAP                _U("IMi018")	/*! 线内无自交叠*/
#define	UGS_LINE_NO_SELF_INTERSECT              _U("IMi019")	/*! 线内无自相交*/
#define	UGS_LINE_COVERED_BY_LINE_CLASS          _U("IMi020")	/*! 线被多条线完全覆盖*/
#define	UGS_LINE_COVERED_BY_AREA_BOUNDARY       _U("IMi021")	/*! 线被面边界覆盖*/
#define	UGS_LINE_ENDPOINT_COVERED_BY_POINT      _U("IMi022")	/*! 线端点必须被点覆盖*/
#define	UGS_LINE_NO_INTERSECTION_WITH_AREA      _U("IMi023")	/*! 线与面无相交*/
#define	UGS_LINE_NO_INTERSECTION_WITH           _U("IMi024")	/*! 线与线无相交*/
#define	UGS_POINT_COVERED_BY_LINE               _U("IMi025")	/*! 点必须在线上*/
#define	UGS_POINT_COVERED_BY_AREA_BOUNDARY      _U("IMi026")	/*! 点必须在面边界上*/
#define	UGS_POIN_INSIDE_AREA                    _U("IMi027")	/*! 点被面完全包含*/
#define	UGS_POINT_COVERED_BY_LINE_ENDPOINT      _U("IMi028")	/*! 点必须被线端点覆盖*/
#define	UGS_POINT_NO_IDENTICAL                  _U("IMi029")	/*! 无重复点*/
#define	UGS_POINT_OUTSIDE_AREA                  _U("IMi030")	/*! 点不能被面包含 */
#define	UGS_NO_MULTIPART                        _U("IMi031")	/*! 无复杂对象*/
#define	UGS_REGION_COVERED_EACH                 _U("IMi032")	/*! 面与面相互覆盖*/
#define	UGS_LARGER_THAN_TOLERANCE               _U("IMi033")	/*! 节点距离必须大于容限*/
#define	UGS_DATASET_INNER_DEL_IDENTICAL1        _U("IMi034")	/*! 数据集内部去重复1*/
#define	UGS_DATASET_INNER_DEL_IDENTICAL2        _U("IMi035")	/*! 数据集内部去重复2*/
#define	UGS_DATASET_INNER_INTERSECTION          _U("IMi036")	/*! 数据集内部求交*/
#define	UGS_START_NODE_ID                       _U("IMi037")	/*! 起始端点ID*/
#define	UGS_END_NODE_ID                         _U("IMi038")	/*! 起始端点ID*/
#define	UGS_LOGICAL_NODE                        _U("IMi039")	/*! 逻辑节点*/
#define	UGS_BUILD_REGION_NODES_UNION            _U("IMi040")	/*! 构面节点合并*/
#define	UGS_DATASETS_INTERSECTION               _U("IMi041")	/*! 数据集之间求交*/
#define	UGS_DEL_IDENTICAL_LINES                 _U("IMi042")	/*! 去重复线*/
#define	UGS_PREPROCESS_SNAP_LINE_BY_POINT       _U("IMi043")	/*! 预处理点捕捉线*/
#define	UGS_MUST_EXIST_INTERSECT_VERTEX         _U("IMi044")	/*! 线段相交处必须存在交点*/
#define	UGS_MUST_MATCH_WITH_VERTEX              _U("IMi045")	/*! 节点之间必须互相匹配*/
#define UGS_NO_REDUNDANT_VERTICES				_U("IMi046")	/*! 无冗余节点*/
#define UGS_LINE_NO_SHARP_ANGLE					_U("IMi047")	/*! 线内无打折*/
#define UGS_LINE_PREPROCESS						_U("IMi048")	/*! 线线预处理...*/
#define UGS_VERTEX_LINE_PREPROCESS				_U("IMi049")	/*! 点线预处理...*/
#define UGS_VERTEX_PREPROCESS					_U("IMi050")	/*! 点预处理...*/
#define UGS_CHECK_POLYGON					    _U("IMi051")	/*! 多边形走向调整...*/

// 地理坐标、位置、方向信息
#define	UGS_EAST                                _U("IMj001")	/*! 东*/
#define	UGS_WEST                                _U("IMj002")	/*! 西*/
#define	UGS_SOUTH                               _U("IMj003")	/*! 南*/
#define	UGS_NORTH                               _U("IMj004")	/*! 北*/
#define	UGS_ARCTICCIRCLE                        _U("IMj005")	/*! 北极圈*/
#define	UGS_TROPICOFCANCER                      _U("IMj006")	/*! 北回归线*/
#define	UGS_EQUATOR                             _U("IMj007")	/*! 赤道*/
#define	UGS_TROPICOFCAPRICORN                   _U("IMj008")	/*! 南回归线*/
#define	UGS_ANTARCTICCIRCLE                     _U("IMj009")	/*! 南极圈*/
#define	UGS_PRIMEMERIDIAN                       _U("IMj010")	/*! 本初子午线*/
#define	UGS_ANTIMERIDIAN                        _U("IMj011")	/*! 国际日期变更线*/
#define	UGS_NORTH_LATITUDE                      _U("IMj012")	/*! 北纬*/
#define	UGS_SOUTH_LATITUDE                      _U("IMj013")	/*! 南纬*/
#define	UGS_EAST_LONGITUDE                      _U("IMj014")	/*! 东经*/
#define	UGS_WEST_LONGITUDE                      _U("IMj015")	/*! 西经*/
#define	UGS_ALTITUDE                            _U("IMj016")	/*! 高度*/
#define	UGS_CAMERA_ALTITUDE                     _U("IMj017")	/*! 相机高度*/
#define	UGS_NORTH_EAST                          _U("IMj018")	/*! 东北*/
#define	UGS_NORTH_WEST                          _U("IMj019")	/*! 西北*/
#define	UGS_SOUTH_WEST                          _U("IMj020")	/*! 西南*/
#define	UGS_SOUTH_EAST                          _U("IMj021")	/*! 东南*/
#define	UGS_END                                 _U("IMj022")	/*! 终点*/
#define	UGS_TURN_LEFT                           _U("IMj023")	/*! 左转*/
#define	UGS_TURN_RIGHT                          _U("IMj024")	/*! 右转*/
#define	UGS_GO_STRAIGHT                         _U("IMj025")	/*! 直行*/
#define	UGS_TURN_AROUND                         _U("IMj026")	/*! 掉头*/
#define	UGS_ON_ROAD                             _U("IMj027")	/*! 上面*/
#define	UGS_LEFT                                _U("IMj028")	/*! 左边*/
#define	UGS_RIGHT                               _U("IMj029")	/*! 右边*/
#define	UGS_DEFAULT_TIMEZONE                    _U("IMj030")	/*! 使用默认时区*/
#define	UGS_MAGNETIC_SOUTH                      _U("IMj031")	/*! 磁南*/
#define	UGS_MAGNETIC_NORTH                      _U("IMj032")	/*! 磁北*/

// 类型
#define	UGS_TABULAR                             _U("IMk001")	/*! 属性数据集*/
#define	UGS_POINT                               _U("IMk002")	/*! 点数据集*/
#define	UGS_LINE                                _U("IMk003")	/*! 线数据集*/
#define	UGS_REGION                              _U("IMk004")	/*! 面数据集*/
#define	UGS_TEXT                                _U("IMk005")	/*! 文本数据集*/
#define	UGS_CAD                                 _U("IMk006")	/*! 复合数据集*/
#define	UGS_UNKNOWN                             _U("IMk007")	/*! 未知*/
#define	UGS_BYTE                                _U("IMk008")	/*! BYTE类型存储*/
#define	UGS_WORD                                _U("IMk009")	/*! WORD类型存储*/
#define	UGS_3BYTE                               _U("IMk010")	/*! 三字节类型存储*/
#define	UGS_4BYTE                               _U("IMk011")	/*! 四字节类型存储*/
#define	UGS_FLOAT                               _U("IMk012")	/*! 浮点型存储*/
#define	UGS_DOUBLE                              _U("IMk013")	/*! 双精度类型存储*/
#define	UGS_DCT                                 _U("IMk014")	/*! Image的压缩*/
#define	UGS_SGL                                 _U("IMk015")	/*! SuperMap Grid LZW encoded*/
#define	UGS_LGL                                 _U("IMk016")	/*! another Grid LZW encoded*/
#define	UGS_LZW                                 _U("IMk017")	/*! 索引色影像的无损压缩*/
#define	UGS_PNG                                 _U("IMk018")	/*! PNG压缩*/
#define	UGS_NOCODE                              _U("IMk019")	/*! 不使用编码方式*/

// 字体
#define	UGS_SONG                                _U("IMl001")	/*! 宋体*/
#define	UGS_BLACK                               _U("IMl002")	/*! 黑体*/
#define	UGS_MSYH                                _U("IMl003")	/*! 微软雅黑*/
#define	UGS_LIKE_SONG                           _U("IMl004")	/*! 仿宋*/
#define	UGS_SQUARE                              _U("IMl005")	/*! 楷体*/

// 其他分析功能，例如叠加分析、网络分析等
#define	UGS_OVERLAY                             _U("IMm001")	/*! 叠加分析*/
#define	UGS_BUFFER_CREATING                     _U("IMm002")	/*! 正在生成缓冲区*/
#define	UGS_PROPER                              _U("IMm003")	/*! 正确*/

//可视化建模功能的输出信息
#define	UGS_SPM_PREPARED						 _U("IMn001")	/*! 准备工作完成*/
#define	UGS_SPM_PROCESSE_DONE					 _U("IMn002")	/*! 完成处理，准备清理环境*/
#define	UGS_SPM_PROCESSE_START					 _U("IMn003")	/*! 启动_U("%s")为_U("%s")的处理*/
#define UGS_SPM_TIF_ALREADY_HAS_PRJ              _U("IMn004")   /*! 文件:%s内部存在投影信息*/
#define UGS_SPM_FUNCTION_SUCCEED              _U("IMn005")   /*! 功能:%s 执行成功*/
#define UGS_SPM_FUNCTION_FAILED              _U("IMn006")   /*! 功能:%s 执行失败*/
#define UGS_SPM_CACHE_BOUNDS_ENTIRE              _U("IMn007")   /*! 输出缓存全部范围*/
#define UGS_SPM_CALC_OUTPUT_SCALES              _U("IMn008")   /*! 计算输出比例尺*/
#define UGS_SPM_SET_OUTPUT_SCALES              _U("IMn009")   /*! 设置输出比例尺*/
#define UGS_SPM_CACHE_START              _U("IMn010")   /*! 开始缓存*/
#define UGS_SPM_CACHE_END              _U("IMn011")   /*! 结束缓存%s*/
#define UGS_SPM_PARAMS_TESTING              _U("IMn012")   /*! &s:参数校验*/
#define UGS_SPM_PARAMS_SETTING              _U("IMn013")   /*! %s:参数设置*/
#define UGS_SPM_FUNCTION_RUNNING              _U("IMn014")   /*! %s:执行*/

//三维填充符号库参数说明信息
#define	UGS_WAVE_SIZE						 _U("IMo001")	/*! 影响水波的大小*/
#define	UGS_WAVE_FREQUENCY					 _U("IMo002")	/*! 影响水波起伏的快慢*/
#define	UGS_REFLECTION_BRIGHTNESS					 _U("IMo003")	/*! 影响水面中反射物体的亮度*/
#define UGS_WAVE_DIRECTION              _U("IMo004")   /*! 影响水流动的方向和速度*/
#define UGS_WATER_BOTTOM_TEXTURE              _U("IMo005")   /*! 影响通过折射看到了水底纹理*/
#define UGS_WATER_COLOR                   _U("IMo006")   /*! 影像水面的色调*/
#define UGS_FRESNELSCALE                   _U("IMo007")   /*! 菲涅耳系数*/
#define UGS_FRESNELPOWER                   _U("IMo008")   /*! 菲涅耳指数*/
#define UGS_NOISESCALE                     _U("IMo009")   /*! 影响水面粗糙程度*/
#define UGS_FRESNELBIAS                  _U("IMo010")   /*! 菲涅耳系数偏移量*/
#define UGS_MINFRESNEL                     _U("IMo011")   /*! 菲涅耳系数取值范围最小值*/
#define UGS_MAXFRESNEL                  _U("IMo012")   /*! 菲涅耳系数取值范围最大值*/

#define	UGS_WAVE_SIZE_LABEL						 _U("IMo001L")	/*! 水波的大小名称标签*/
#define	UGS_WAVE_FREQUENCY_LABEL				 _U("IMo002L")	/*! 影响水波起伏的快慢名称标签*/
#define	UGS_REFLECTION_BRIGHTNESS_LABEL			 _U("IMo003L")	/*! 影响水面中反射物体的亮度名称标签*/
#define UGS_WAVE_DIRECTION_LABEL                 _U("IMo004L")   /*! 影响水流动的方向和速度名称标签*/
#define UGS_WATER_BOTTOM_TEXTURE_LABEL           _U("IMo005L")   /*! 影响通过折射看到了水底纹理名称标签*/
#define UGS_WATER_COLOR_LABEL                    _U("IMo006L")   /*! 影像水面的色调名称标签*/
#define UGS_FRESNELSCALE_LABEL                   _U("IMo007L")   /*! 菲涅耳系数名称标签*/
#define UGS_FRESNELPOWER_LABEL                   _U("IMo008L")   /*! 菲涅耳指数名称标签*/
#define UGS_NOISESCALE_LABEL                     _U("IMo009L")   /*! 影响水面粗糙程度名称标签*/
#define UGS_FRESNELBIAS_LABEL                    _U("IMo010L")   /*! 菲涅耳偏移量标签*/
#define UGS_MINFRESNEL_LABEL                     _U("IMo011L")   /*! 菲涅耳系数取值范围最小值*/
#define UGS_MAXFRESNEL_LABEL                     _U("IMo012L")   /*! 菲涅耳系数取值范围最大值*/

//常规操作日志
#define UGS_LOG_PREPARE_CREATE_DS				_U("IMu001")    /*"准备创建数据源..."*///xiaohua

#define UGS_LOG_CREATE_DS_SUCCESS				_U("IMu002")    /*"创建数据源成功!"*///xiaohua

#define UGS_LOG_PREPARE_OPEN_DS					_U("IMu003")    /*"准备打开数据源..."*///xiaohua

#define UGS_LOG_OPEN_DS_SUCCESS					_U("IMu004")    /*"打开数据源成功!"*///xiaohua

#define UGS_LOG_PREPARE_CLOSE_DS				_U("IMu005")    /*"关闭数据源..."*///xiaohua

#define UGS_LOG_CREATING_TABLE					_U("IMu006")    /*"创建(%s)表..."*/

#define UGS_LOG_CHANGE_PASS						_U("IMu007")    /*"修改密码"*///xiaohua

#define UGS_LOG_BEGIN_TRANS						_U("IMu008")    /*"开始事务"*/

#define UGS_LOG_COMMIT_TRANS					_U("IMu009")    /*"提交事务"*/

#define UGS_LOG_ROLLBACK_TRANS					_U("IMu010")    /*"回滚事务"*/

#define UGS_LOG_READING_INFO_OF_VDT				_U("IMu011")    /*"正在读取矢量数据集(%s)的相关信息..."*/




#define UGS_LOG_READING_INFO_OF_RDT				_U("IMu012")    /*"正在读取栅格数据集(%s)的相关信息..."*/

#define UGS_LOG_LOGIN_LONG_TRANS				_U("IMu013")    /*"登录数据源(%s)的长事务环境"*/

#define UGS_LOG_LOGOUT_LONG_TRANS				_U("IMu014")    /*"退出数据源(%s)的长事务环境"*/

#define UGS_LOG_LONG_TRANS_LOCK_DATA			_U("IMu015")    /*"{%s}按长事务方式锁定数据"*/

#define UGS_LOG_LONG_TRANS_UNLOCK_DATA			_U("IMu016")    /*"{%s}按长事务方式解锁数据"*/

#define UGS_LOG_LONG_TRANS_ROLLBACK				_U("IMu017")    /*"{%s}按长事务方式回滚操作"*/

#define UGS_LOG_CREATE_VECTOR					_U("IMu018")    /*"创建矢量数据集：%s"*///xiaohua

#define UGS_LOG_CREATE_RASTER					_U("IMu019")    /*"创建栅格数据集：%s"*///xiaohua

#define UGS_LOG_DELETE_DATASET					_U("IMu020")    /*"删除数据集：%s"*///xiaohua

#define UGS_LOG_DV_APPEND						_U("IMu021")    /*"向矢量数据集 (%s) 中追加记录"*///xiaohua

#define UGS_LOG_DV_BUILD_SPATIAL_INDEX			_U("IMu022")    /*"为矢量数据集 (%s) 建立空间索引 ... ..."*///xiaohua

#define UGS_LOG_DV_COMPUTE_BOUNDS				_U("IMu023")    /*"为矢量数据集 ( %s ) 计算范围..."*///xiaohua

#define UGS_LOG_DV_CREATE_FIELD					_U("IMu024")    /*"为矢量数据集 ( %s ) 创建字段 ( %s ) ..."*///xiaohua

#define UGS_LOG_DV_DELETE_FIELD					_U("IMu025")    /*"为矢量数据集( %s ) 删除字段 ( %s )"*///xiaohua

#define UGS_LOG_DV_CREATE_INDEX					_U("IMu026")    /*"为矢量数据集 (%s) 创建字段索引 ( %s )"*///xiaohua

#define UGS_LOG_DV_DROP_INDEX					_U("IMu027")    /*"为矢量数据集 ( %s ) 移除索引 ( %s ) "*///xiaohua




#define UGS_LOG_DV_RENAME						_U("IMu028")    /*"将矢量数据集 ( %s ) 重命名为：( %s )"*/

#define UGS_LOG_DV_RESET_BOUNDS					_U("IMu029")    /*"矢量数据集( %s )重设Bounds。"*/

#define UGS_LOG_DV_SET_FIELD_INFO				_U("IMu030")    /*"矢量数据集 ( %s ) : 修改字段 ( %s ) 的相关信息"*/

#define UGS_LOG_RS_ADD_RECORDSET				_U("IMu031")    /*"数据集(%s)的记录集添加了一条记录"*///xiaohua

#define UGS_LOG_RS_DELETE_RECORDSET				_U("IMu032")    /*"数据集(%s)的记录集删除了一条记录"*///xiaohua

#define UGS_LOG_RS_MODIFY_RECORDSET				_U("IMu033")    /*"数据集(%s)的记录集修改了一条记录"*///xiaohua

#define UGS_LOG_CALC_EXTREMUM					_U("IMu034")    /*"计算字段 %s 的极值"*/

#define UGS_LOG_OPEN_DV							_U("IMu035")    /*"打开矢量数据集 (%s)！"*///xiaohua

#define UGS_LOG_CLOSE_DV						_U("IMu036")    /* "关闭矢量数据集(%s)"*///xiaohua

#define UGS_LOG_CONNECT_DS						_U("IMu037")    /*"数据源{%s}连接到数据库"*/

#define UGS_LOG_COPYDATASET						_U("IMu038")    /*"数据源{%s}复制数据集{%s}"*///xiaohua

#define UGS_LOG_DV_ADDMETADATADESC				_U("IMu039")    /*"矢量数据集(%s)添加元数据"*/

#define UGS_LOG_DV_LONGTRAN_CHECKIN				_U("IMu040")    /*"矢量数据集(%s)按长事务方式提交修改"*/

#define UGS_LOG_DV_LONGTRAN_CHECKOUT			_U("IMu041")    /*"矢量数据集(%s)按长事务方式锁定记录"*/

#define UGS_LOG_DV_CLEARMETADATADESC			_U("IMu042")    /*"矢量数据集(%s)清除元数据"*/  

#define UGS_LOG_DV_COPYFIELD					_U("IMu043")    /*"矢量数据集(%s)复制字段(%s)"*///xiaohua




#define UGS_LOG_DV_DELETEMETADATADESC			_U("IMu044")    /*"矢量数据集(%s)删除元数据节点"*/

#define UGS_LOG_OPEN_DR							_U("IMu045")    /*"打开栅格数据集(%s)"*///xiaohua

#define UGS_LOG_CLOSE_DR						_U("IMu046")    /*"关闭栅格数据集(%s)"*///xiaohua

#define UGS_LOG_DR_CREATEECW					_U("IMu047")    /*"创建ECW文件(%s)的外部连接"*/

#define UGS_LOG_DR_CREATEMRSID					_U("IMu048")    /*"创建MrSID文件(%s)的外部连接"*/

#define UGS_LOG_DR_RESET						_U("IMu049")    /*"栅格数据集(%s)图层清空"*/

#define UGS_LOG_DV_TRUNCATE						_U("IMu050")    /*"矢量数据集(%s)清空数据"*/

#define UGS_LOG_DR_RELEASEPYRAMIDDATASETS		_U("IMu051")    /*"栅格数据集(%s)释放影像金字塔数据集"*/

#define UGS_LOG_DR_ADDMETADATADESC				_U("IMu052")    /*"栅格数据集(%s)添加元数据"*/

#define UGS_LOG_DR_CLEARMETADATADESC			_U("IMu053")    /*"栅格数据集(%s)清除元数据"*/

#define UGS_LOG_DR_DELETEMETADATADESC			_U("IMu054")    /*"栅格数据集(%s)删除元数据描述的节点"*/

#define UGS_LOG_DR_REMOVEPYRAMIDS				_U("IMu055")    /*"栅格数据集(%s)删除影像金字塔"*///xiaohua

#define UGS_LOG_DR_BUILDPYRAMID					_U("IMu056")    /*"栅格数据集(%s)建立影像金字塔"*///xiaohua

#define UGS_LOG_RS_DELETEALL					_U("IMu057")    /*"记录集删除所有记录"*///xiaohua

#define UGS_LOG_DV_LONGTRAN_UNDOCHECKOUT		_U("IMu058")    /*"矢量数据集(%s) 按长事务方式取消锁定"*/

#define UGS_LOG_DV_SETFIELDINFO					_U("IMu059")    /*"矢量数据集(%s) 设置字段(%s) 属性"*/




#define UGS_LOG_DV_UPDATEFIELD					_U("IMu060")    /*"矢量数据集(%s) 更新字段(%s) 属性"*/

#define UGS_LOG_RS_CHECKIN						_U("IMu061")    /*"提交对当前记录集所做的修改"*/

#define UGS_LOG_RS_CHECKOUT						_U("IMu062")    /*"将记录集查询出来的且没有被别人锁定的记录锁定"*/

#define UGS_LOG_RS_UNDOCHECKOUT					_U("IMu063")    /*"放弃对当前记录集所做的修改"*/

#define UGS_LOG_RS_CHECKINCURRENT				_U("IMu064")    /*"提交对当前记录所做的修改"*/

#define UGS_LOG_RS_CHECKOUTCURRENT				_U("IMu065")    /*"锁定当前记录"*/

#define UGS_LOG_RS_UNDOCHECKOUTCURRENT			_U("IMu066")    /*"撤消对当前记录所做的修改"*/

#define UGS_LOG_RS_COPYFIELD					_U("IMu067")    /*"记录集复制字段(%s)"*///xiaohua

#define UGS_LOG_RS_SETFIELDVALUE				_U("IMu068")    /*"记录集修改当前属性字段值"*/

#define UGS_LOG_RS_SETGEOMETRY					_U("IMu069")    /*"记录集修改当前空间数据"*/

#define UGS_LOG_DV_QUERYFIELDINFOS				_U("IMu070")    /*"矢量数据集(%s) 查询字段集合"*///xiaohua

#define UGS_LOG_DV_STATISTIC					_U("IMu071")    /*"矢量数据集(%s)执行统计操作"*///xiaohua

#define UGS_LOG_DV_CALCULATEEXTREMUM			_U("IMu072")    /*"矢量数据集(%s) 计算极值"*/

#define UGS_LOG_DV_COMPUTERBOUNDS				_U("IMu073")    /*"矢量数据集(%s) 计算边界"*///xiaohua

#define UGS_LOG_DR_SAVEBLOCK					_U("IMu074")    /*"栅格数据集(%s) 保存影像数据到存储设备"*///xiaohua

#define UGS_LOG_DR_LOADBLOCK					_U("IMu075")    /*"栅格数据集(%s) 读取影像数据"*///xiaohua

#define UGS_LOG_DR_UPDATE						_U("IMu0102")	/*"栅格数据集(%s) 更新"*/






#define UGS_LOG_RS_FINDFIRST					_U("IMu076")    /*"记录集光标移到第一个位置"*///xiaohua

#define UGS_LOG_RS_FINDLAST						_U("IMu077")    /*"记录集光标移到最后一个位置"*///xiaohua

#define UGS_LOG_RS_FINDNEXT						_U("IMu078")    /*"记录集光标移到下一个位置"*///xiaohua

#define UGS_LOG_RS_FINDPREV						_U("IMu079")    /*"记录集光标移到前一个位置"*///xiaohua

#define UGS_LOG_RS_SEEKBYID						_U("IMu080")    /*"根据ID移动记录集光标"*///xiaohua

#define UGS_LOG_RS_STATISTIC					_U("IMu081")    /*"记录集执行统计操作"*///xiaohua

#define UGS_LOG_RS_CREATEWITHBOUNDS				_U("IMu082")    /*"记录集执行Bounds查询"*///xiaohua

#define UGS_LOG_RS_CREATEWITHGENERAL			_U("IMu083")    /*"记录集执行普通查询"*///xiaohua

#define UGS_LOG_RS_CREATEWITHIDS				_U("IMu084")    /*"记录集执行IDS查询"*///xiaohua

#define UGS_LOG_RS_CREATEWITHSPATIAL			_U("IMu085")    /*"记录集执行空间查询"*/

#define UGS_LOG_RS_COMPUTERBOUNDS				_U("IMu086")    /*"记录集计算边界"*///xiaohua

#define UGS_LOG_RS_FLUSHCURRENTRECORDSET		_U("IMu087")    /*"记录集提交当前记录到存储设备"*/

#define UGS_LOG_RS_MODIFY						_U("IMu088")    /*"记录集正在执行更新操作..."*/
   
#define UGS_LOG_RS_UPDATE						_U("IMu089")    /*"记录集更新成功"*///xiaohua

#define UGS_LOG_CREATEDATASET					_U("IMu090")    /*"数据源(%s)创建数据集(%s)"*/

#define UGS_LOG_DS_CONNECT						_U("IMu091")    /*"数据源(%s)建立连接"*///xiaohua

#define UGS__LOG_DR_RENAME						_U("IMu092")    /*"将栅格数据集 (%s) 重命名为 (%s)"*/

#define UGS_LOG_VM_CREATE						_U("IMu093")	/*"创建版本 (%s)"*/
#define UGS_LOG_VM_DELETE						_U("IMu094")	/*"删除版本 (%s)"*/
#define UGS_LOG_VM_SWAP							_U("IMu095")	/*"切换版本 (%s)"*/
#define UGS_LOG_VM_UPDATEINFO					_U("IMu096")	/*"修改版本信息 (%s)"*/
#define UGS_LOG_VM_REGISTER						_U("IMu097")	/*"注册版本数据集 (%s)"*/
#define UGS_LOG_VM_UNREGISTER					_U("IMu098")	/*"反注册版本数据集 (%s)"*/
#define UGS_LOG_VM_RECONCILE					_U("IMu099")	/*"版本协调 (%s)"*/
#define UGS_LOG_VM_COMMIT						_U("IMu0100")	/*"版本提交 (%s)"*/
#define UGS_LOG_VM_TRANCONFLICT					_U("IMu0101")	/*"版本冲突解决 (%s)"*/

#define  UGS_LOG_DV_PJCONVERT					_U("IMu0103")	/*"矢量数据集(%s) 投影转换"*/

#define  UGS_LOG_DR_PJCONVERT					_U("IMu0104")	/*"栅格数据集(%s) 投影转换"*/

#define  UGS_LOG_DR_CLIP						_U("IMu0105")	/*"栅格数据集 (%s) 裁剪"*/
#define  UGS_LOG_DR_RESAMPLE					_U("IMu0106")	/*"栅格数据集 (%s) 重采样"*/
#define  UGS_LOG_DR_MATH_ANALYST				_U("IMu0107")	/*"栅格数据集 (%s) 代数运算"*/

//3dsMax插件说明信息
#define UGS_MAX_MENU        _U("IMp000") /*超图Max插件*/
#define UGS_MAX_BATCH_IMPORT         _U("IMp001")   /*批量导入模型*/
#define UGS_MAX_BATCH_EXPORT          _U("IMp002")   /*批量导出模型*/ 
#define UGS_MAX_SCRIPT                     _U("IMp003")   /*脚本工具*/
#define UGS_MAX_IMPORT_TERRAIN        _U("IMp004")    /*导入地形*/
#define UGS_MAX_EXPORT_TERRAIN         _U("IMp005")    /*导出地形*/
#define UGS_MAX_BATCH_CONVERT_TERRAIN       _U("IMp006")    /*批量转换地形*/
#define UGS_MAX_EXPORT_REGION3D       _U("IMp007")   /*导出三维面*/
#define UGS_MAX_EXPORT_DATASET        _U("IMp008")   /*生成数据集*/
#define UGS_MAX_EXPORT_CACHE            _U("IMp009")   /*生成缓存*/
#define UGS_MAX_APPEND_CACHE            _U("IMp010")   /*追加到缓存中*/
#define UGS_MAX_EXPORT_KML               _U("IMp011")    /*生成KML*/
#define UGS_MAX_TEXTURE_SETTING       _U("IMp012")    /*纹理设置*/
#define UGS_MAX_HELP                          _U("IMp013")    /*帮助*/
#define UGS_MAX_ABOUT                       _U("IMp014")     /*关于*/

#define UGS_MAX_ERROR   _U("IMp015")   /*错误*/
#define UGS_MAX_HINT   _U("IMp016")    /*提示*/
#define UGS_MAX_CONVERT  _U("IMp017")  /*转换*/
#define UGS_MAX_ORIGINAL  _U("IMp018")   /*原始*/
#define UGS_MAX_COMPACT  _U("IMp019")  /*紧凑*/
#define UGS_MAX_SAVE_FAIL _U("IMp020")  /*保存失败*/
#define UGS_MAX_SAVE_SUCCESS  _U("IMp021")  /*保存成功*/
#define UGS_MAX_IMPORT_FAIL  _U("IMp022")  /*导入失败*/

#define UGS_MAX_LATLONG_HINT  _U("IMp023")  /*经纬度信息请输入正确的数值类型（整数或者小数）*/
#define UGS_MAX_LATLONG_WARNING  _U("IMp024")  /*经纬度信息超过正常大小*/
#define UGS_MAX_LIMITS_WARNING  _U("IMp025")  /*导入范围未设置*/
#define UGS_MAX_LOCATION_NOT_FULL  _U("IMp026")  /*插入点经纬度输入不全*/

#define UGS_MAX_FILE_PATH_HINT  _U("IMp027")  /*指示文件路径*/
#define UGS_MAX_TEXTURE_PATH_HINT  _U("IMp028")  /*请指明所需纹理路径*/

#define UGS_MAX_SCENE_IS_NULL  _U("IMp029")  /*场景中没有数据*/
#define UGS_MAX_REGION3D_IS_NULL  _U("IMp030")  /*场景中没有可导出的三维面数据*/

#define UGS_MAX_EXPORT_MODEL_COUNT  _U("IMp031")  /*导出%d个模型*/
#define UGS_MAX_EXPORT_END  _U("IMp032")  /*导出完毕*/
#define UGS_MAX_ADD_MODEL_COUNT  _U("IMp033")  /*添加%d个模型*/

#define UGS_MAX_DATASET_NAME_IS_NULL   _U("IMp034")  /*数据集名称为空*/
#define UGS_MAX_IMAGE_IS_NONENTITY  _U("IMp035")  /*影像数据为空*/

#define UGS_MAX_TERRAIN_IS_NONENTITY  _U("IMp036")  /*未包含有效的地形数据*/
#define UGS_MAX_SCT_WARNING  _U("IMp037")  /*SCT地形缓存暂不支持修改后导出*/
#define UGS_MAX_OUTPUT_PATH  _U("IMp038")  /*输出路径*/
#define UGS_MAX_SUCCESS    _U("IMp039")  /*成功*/
#define UGS_MAX_OUTPUT_FAIL  _U("IMp040")  /*导出失败*/
#define UGS_MAX_OUTPUT_SUCCESS  _U("IMp041")   /*导出成功*/

//场景输出相关信息
#define UGS_FLAT_OUTPUT_ENTERMOUSEKEYROAM        _U("IMp100") /*进入键鼠漫游模式，Esc或鼠标右键退出，+或-更改步长*/
#define UGS_FLAT_OUTPUT_ROAMSTEPADJUST         _U("IMp101")   /*漫游步长*/
#define UGS_FLAT_OUTPUT_EXITMOUSEKEYROAM         _U("IMp102")   /*退出键鼠漫游模式*/ 

#define UGS_SCENE_FRAMESTATE_AVGFPS						_U("IMp103") /*平均帧率_*/
#define UGS_SCENE_FRAMESTATE_BESTFPS						_U("IMp104") /*最好帧率_*/
#define UGS_SCENE_FRAMESTATE_WORSTFPS					_U("IMp105")/*最差帧率_*/
#define UGS_SCENE_FRAMESTATE_TRIANGLESCOUNT	_U("IMp106")/*三角面数量_*/

// 海图相关
#define UGS_CHART_HAVENOS57DATASETEXTINFO _U("IMs001") /* 数据集没有S-57数据集扩展信息 */
#define UGS_CHART_GENERATINGRCIDSEQFAILED _U("IMs002") /* 创建特征物标对象记录ID序列失败 */
#define UGS_CHART_FIDNSEQNAMENULL _U("IMs003") /*FIDN序列名称为空*/
#define UGS_CHART_GETFIDNVALUEFAILED _U("IMs004") /*从序列中获取FIDN值失败*/
#define UGS_CHART_RCIDSEQNAMENULL _U("IMs005") /*特征物标记录ID序列名称为空*/
#define UGS_CHART_GETRCIDVALUEFAILED _U("IMs006") /*从序列中获取RCID值失败*/
#define UGS_CHART_ISONODEIDREP _U("IMs007") /*孤立节点RCID值重复*/
#define UGS_CHART_CONNODEIDREP _U("IMs008") /*连接节点RCID值重复*/
#define UGS_CHART_VECTOREDGERCIDREP _U("IMs009") /*空间线段RCID值重复*/
#define UGS_CHART_LOADFVEFAILED _U("IMs010") /*加载特征物标对象到空间线段对象的引用关系失败*/
#define UGS_CHART_LOADFVPFAILED _U("IMs011") /*加载特征物标对象到空间节点对象的引用关系失败*/
#define UGS_CHART_FEATUREOBJREADFSPTFAILED _U("IMs012") /*特征物标对象 FE%010u 获取特征物标对象到空间对象的引用关系失败*/
#define UGS_CHART_GETISONODEFAILED _U("IMs013") /*获取孤立节点对象 VI%010u 失败*/
#define UGS_CHART_GETCONNODEFAILED _U("IMs014") /*获取连接节点对象 VC%010u 失败*/
#define UGS_CHART_GETEDGENODEFAILED _U("IMs015") /*获取空间线段对象 VE%010u 失败*/
#define UGS_CHART_S58CHECKRES _U("IMs016") /*S58 ID=%d : %s */
#define UGS_CHART_VALIDATE_AGENCYINVALID _U("IMs017") /*机构编码值 %d 无效*/
#define UGS_CHART_VALIDATE_CELLNAMEINVALID _U("IMs018") /*海图图幅名称 %s 无效*/
#define UGS_CHART_VALIDATE_ATTFLEXICALLEVELINVALID _U("IMs019") /*ATTF字符等级无效，ATTF字符等级只能为0和1*/
#define UGS_CHART_VALIDATE_NATFLEXICALLEVELINVALID _U("IMs020") /*NATF字符等级无效，NATF字符等级只能为0,1和2*/
#define UGS_CHART_VALIDATE_VERTICALDATUMINVALID _U("IMs021") /*垂直基准面值无效，垂直基准面值必须取自S-57属性VERDAT的值域*/
#define UGS_CHART_VALIDATE_SOUNDINGDATUMINVALID _U("IMs022") /*水深基准面值无效，水深基准面值必须取自S-57属性VERDAT的值域*/
#define UGS_CHART_VALIDATE_CSCLVALID _U("IMs023") /*编辑比例尺系数无效*/
#define UGS_CHART_VALIDATE_COORDINATEMUTFACTORINVALUD _U("IMs024") /*坐标值由浮点变为正数的乘数因子值无效*/
#define UGS_CHART_VALIDATE_FEATURERCIDINVALID _U("IMs025") /*%s 特征物标对象 %s SmID=%d RCID值无效*/
#define UGS_CHART_VALIDATE_FEATUREFOIDINVALID _U("IMs026") /*%s 特征物标对象 %s SmID=%d FOID值无效*/
#define UGS_CHART_VALIDATE_FOIDREPEATE _U("IMs027") /*特征物标对象 %s FOID值重复*/
#define UGS_CHART_VALIDATE_FEATURERCIDREPEATE _U("IMs028") /*特征物标对象 %s RCID值重复*/
#define UGS_CHART_VALIDATE_ISONODENOTREFERENCED _U("IMs029") /*孤立节点对象 VI%010u 没有被任何特征物标对象引用*/
#define UGS_CHART_VALIDATE_CONNODENOTREFERENCED _U("IMs030") /*连接结点对象 VC%010u 没有被任何空间线段对象引用*/
#define UGS_CHART_VALIDATE_EDGENODENOTREFERENCED _U("IMs031") /*空间线段对象 VE%010u 没有被任何特征物标对象引用*/
#define UGS_CHART_VALIDATE_EDGESTARTNODEIDVALID _U("IMs032") /*空间线段对象 VE%010u 读取开始连接节点ID失败*/
#define UGS_CHART_VALIDATE_EDGEENDNODEIDVALID _U("IMs033") /*空间线段对象 VE%010u 读取终止连接节点ID失败*/
#define UGS_CHART_VALIDATE_EDGESTARTNODEVALID _U("IMs034") /*空间线段对象 VE%010u 开始连接结点ID VC%010u 无效*/
#define UGS_CHART_VALIDATE_EDGEENDNODEVALID _U("IMs035") /*空间线段对象 VE%010u 终止连接结点ID VC%010u 无效*/
#define UGS_CHART_VALIDATE_SOUDINGNODEPTH _U("IMs036") /*水深特征物标对象 FE%010u 空间点 SmID=%d 没有水深值*/
#define UGS_CHART_VALIDATE_SAMESOUNDINGGROUPATTRIBUTENOTEQ _U("IMs037") /*属于同一分组下的水深对象 FE%010u，其属性 %s 值不相等*/
#define UGS_CHART_VALIDATE_FOIDNOTFINDFEATURE _U("IMs038")/* 在特征物标对象关系表中，FOID=%s 的记录找不到对应的特征物标对象*/
#define UGS_CHART_VALIDATE_SLAVENOTREFMORETHANONEFEATURE _U("IMs039") /*在主从关系中，从属物标对象 %s %s 被多于一个主物标对象所引用*/
#define UGS_CHART_VALIDATE_FEATURENOTREFITSELF _U("IMs040") /* 在特征物标对象关系中，特征物标对象 %s %s 引用其本身 */
#define UGS_CHART_VALIDATE_MASTERREFSAMESALVEMOREONE _U("IMs041") /* 在主从关系中，主物标对象 %s %s 引用同一从属物标对象 %s %s 超过一次*/
#define UGS_CHART_VALIDATE_SLAVENOTSHAREMASTERNODE _U("IMs042") /* 在主从关系中，从属物标对象 %s %s 不与点状主物标对象%s %s公用相同的空间点 */
#define UGS_CHART_VALIDATE_SLAVENOTSITUTEMASTERLINE _U("IMs043") /* 在主从关系中，从属物标对象 %s %s 不落在线状主物标对象 %s %s 的线上*/
#define UGS_CHART_VALIDATE_SLAVENOTWITHINMASTERREGION _U("IMs044") /*在主从关系中，从属物标对象 %s %s 不落在面状主物标对象 %s %s的内部*/
#define UGS_CHART_VALIDATE_COLLECTIONREFFEATURELESSTHANTWO _U("IMs045") /*关联物标 %s %s 所关联的特征物标数目少于2*/
#define UGS_CHART_VALIDATE_PEERRELATIONNOTPEER _U("IMs046") /*在一个平等关系中，关联物标 %s %s 所关联的特征物标 %s %s 并非平等关系*/
#define UGS_CHART_VALIDATE_MORETHANONEMASTERINCOLLECTION _U("IMs047") /*关联物标%s %s 所关联的特征物标对象主物标对象数目多于一个*/
#define UGS_CHART_VALIDATE_COLLECTIONNOTALLSLAVES _U("IMs048") /*关联物标 %s %s 关联一个主物标对象，但所关联的其他特征物标对象中 %s %s 并非一个从属物标对象*/
#define UGS_CHART_VALIDATE_POINTFEATUREREFVALUEINVALID _U("IMs049") /*点特征物标对象 %s FE%010u 所引用的 %s%010u %s=%d 值无效*/
#define UGS_CHART_VALIDATE_LINETFEATUREREFVALUEINVALID _U("IMs050") /*线特征物标对象 %s FE%010u 所引用的 %s%010u %s=%d 值无效*/
#define UGS_CHART_VALIDATE_REGIONFEATUREREFVALUEINVALID _U("IMs051") /*面特征物标对象 %s FE%010u 所引用的 %s%010u %s=%d 值无效*/
#define UGS_CHART_VALIDATE_SPATIALATTRIBUTEHASVALUE _U("IMs052") /* %s %s%010u 空间属性 %s 有值 */
#define UGS_CHART_VALIDATE_SPATIALATTRIBUTEVALUEINVALID _U("IMs053") /* %s %s%010u 空间属性 QUAPOS 值无效*/
#define UGS_CHART_VALIDATE_COALNESPATIALERROR1 _U("IMs054") /* 特征物标对象 COALNE FE%010u 属性CATCOA=%d，与属性CATLND含有值%d的%s FE%010u 邻接，但是COALNE所引用的空间线段的空间属性QUAPOS != 4*/
#define UGS_CHART_VALIDATE_REGIONFEATUREREFVALUEINVALID2 _U("IMs055") /*面特征物标对象 %s FE%010u 所引用 VE%010u USAG=%d MASK=%d 值无效*/
#define UGS_CHART_S58_ISACOLLECTIONCOMPONENT _U("IMs056") /*被关联物标对象所关联*/
#define UGS_CHART_S58_ISASLAVE _U("IMs057") /*是一个从属特征物标对象*/
#define UGS_CHART_S58_ISGROUP1 _U("IMs058") /*是Group 1对象*/
#define UGS_CHART_S58_ISGEOOBJECT _U("IMs059") /*是地理特征物标对象*/
#define UGS_CHART_S58_ISGROUP2 _U("IMs060") /*是Group 2对象*/
#define UGS_CHART_S58_ISMETA _U("IMs061") /*是元物标对象*/
#define UGS_CHART_S58_FEATUREERROR _U("IMs062") /* 特征物标 %s FE%010u SmID=%d %s*/
#define UGS_CHART_S58_GEOMETRYTYPEIS _U("IMs063") /*几何对象类型是 %s*/
#define UGS_CHART_S58_GEOMETRYTYPEISNOT _U("IMs064") /*几何对象类型不是 %s*/
#define UGS_CHART_S58_ATTRIBUTEHASVALUE _U("IMs065") /*属性 %s 有有效的属性值*/
#define UGS_CHART_S58_ATTRIBUTEHASVALUENOT _U("IMs066") /*属性 %s 没有有效的属性值*/
#define UGS_CHART_S58_ATTRIBUTECOMPAREDEPTH _U("IMs067") /*%s 属性值 %s SOUNDG 对象的水深值*/
#define UGS_CHART_S58_ATTRIBUTECOMPARESOURCEFEATURE _U("IMs068") /* %s 属性值 %s 源特征物标对象 %s 属性值*/
#define UGS_CHART_S58_ATTRIBUTECOMPARE _U("IMs069") /*%s 属性值 %s %s 属性值*/
#define UGS_CHART_S58_ATTRIBUTECOMPAREVALUE _U("IMs070") /* %s 属性值 %s %s */
#define UGS_CHART_S58_ATTRIBUTECOMPAREVALUERECIPROCAL _U("IMs071") /* %s 属性值 %s 与源特征物标对象 %s 属性值相反*/
#define UGS_CHART_S58_ATTRIBUTECOMPAREVALUERECIPROCALNOT _U("IMs072") /* %s 属性值 %s 不与源特征物标对象 %s 属性值相反*/
#define UGS_CHART_S58_ATTRIBUTEHAVENOVALUE _U("IMs073") /*属性字段 %s 没有属性值*/
#define UGS_CHART_S58_ATTRIBUTECONTAINVALUE _U("IMs074") /*属性字段 %s 包含属性值 %s */
#define UGS_CHART_S58_ATTRIBUTECONTAINVALUENOT _U("IMs075") /*属性字段 %s 不包含属性值 %s */
#define UGS_CHART_S58_ATTRIBUTEVALUEUNDEF _U("IMs076") /* 属性字段 %s 没有定义任何属性值（Unknown和有效的属性值）*/
#define UGS_CHART_S58_ATTRIBUTEVALUEDEF _U("IMs077") /* 属性字段 %s 定义了属性值（Unknown或有效的属性值）*/
#define UGS_CHART_S58_ATTRIBUTEVALUEUNKNOWN _U("IMs078") /*属性字段 %s 属性值 Unknown*/
#define UGS_CHART_S58_ATTRIBUTEVALUEKNOWN _U("IMs079") /*属性字段 %s 属性值有效(并非Unknown)*/
#define UGS_CHART_S58_ATTRIBUTEVALUEEQAUDIRECTIONOFDIGITIZING _U("IMs080") /*属性字段 %s 属性值与线段在数字地图上的方向角度相同*/
#define UGS_CHART_S58_ATTRIBUTEVALUEEQAUDIRECTIONOFDIGITIZINGRECIPROCAL _U("IMs081") /*属性字段 %s 属性值与线段在数字地图上的方向角度相反*/
#define UGS_CHART_S58_ATTRIBUTEVALUEEQAUDIRECTIONOFDIGITIZINGNOT _U("IMs082") /*属性字段 %s 属性值与线段在数字地图上的方向角度不相同*/
#define UGS_CHART_S58_ATTRIBUTEVALUEEQAUDIRECTIONOFDIGITIZINGRECIPROCALNOT _U("IMs083") /*属性字段 %s 属性值与线段在数字地图上的反向角度不相同*/
#define UGS_CHART_S58_NOTANYFEATURECOMPONENT _U("IMs084") /*不被任何 %s 特征物标所关联*/
#define UGS_CAHRT_S58_ISACOMPONENTOF _U("IMs085") /*被物标对象 %s 所关联*/
#define UGS_CHART_S58_NOTANTFEATURESLAVE _U("IMs086") /*不是任何特征物标对象的从属物标*/
#define UGS_CHART_S58_ISASLAVEOF _U("IMs087") /*是特征物标对象 %s 的从属物标*/
#define UGS_CHART_S58_HAVENOANYCOMPONENT _U("IMs088") /*没有关联任何特征物标对象*/
#define UGS_CHART_S58_HAVECOMPONETOF _U("IMs089") /*关联特征物标对象 %s */
#define UGS_CHART_S58_HAVENOTCOMPONETOF _U("IMs090") /*没有关联特征物标对象 %s */
#define UGS_CHART_S58_HAVASLAVEFEATURE _U("IMs091") /*有从属物标 %s */
#define UGS_CHART_S58_HAVENOANYSLAVEFEATURE _U("IMs092") /*没有任何从属物标*/
#define UGS_CHART_S58_HAVENOSLAVEFEATURE _U("IMs093") /*没有从属物标 %s */
#define UGS_CHART_S58_OVERLAPFEATURE _U("IMs094") /*与特征物标对象 %s 叠加(Overlap)*/
#define UGS_CHART_S58_CONTAINSFEATURE _U("IMs095") /*包含特征物标对象 %s (Contains)*/
#define UGS_CHART_S58_ISWITHINFEATURE _U("IMs096") /*在特征物标对象 %s 里面(IsWithin)*/
#define UGS_CHART_S58_TOUCHESFEATURE _U("IMs097") /*与特征物标对象 %s 邻接(Touches)*/
#define UGS_CHART_S58_NOTOVERLAPANYFEATURE _U("IMs098") /*不与任何特征物标对象叠加(Overlap)*/
#define UGS_CHART_S58_NOTCONTAINSANYFEATURE _U("IMs099") /*不包含任何特征物标对象(Contains)*/
#define UGS_CHART_S58_NOTISWITHINANYFEATURE _U("IMs100") /*不落在任何特征物标对象里面(IsWithin)*/
#define UGS_CHART_S58_NOTTOUCHESANYFEATURE _U("IMs101") /*不与任何特征物标对象邻接(Touches)*/
#define UGS_CHART_S58_NOTSHARESANYFEATURE _U("IMs102") /*不与任何特征物标对象共用几何对象*/
#define UGS_CHART_S58_SHARESFEATURE _U("IMs103") /*与特征物标对象 %s 共用几何对象*/
#define UGS_CHART_S58_NOTEQUALANYFEATURE _U("IMs104") /*不与任何特征物标对象的几何对象一致(Equal)*/
#define UGS_CHART_S58_EQUALFEATURE _U("IMs105") /*与特征物标对象 %s 的几何对象一致(Equal)*/
#define UGC_CHART_PGS_UPFOID _U("IMs106") /*正在更新特征物标FOID值*/
#define UGS_CHART_PGS_CHECKCHAINNODETOPO _U("IMs107") /*正在进行S-57连接节点拓扑关系检查...*/
#define UGS_CHART_PGS_CHARTVINODE _U("IMs108") /*正在检查孤立节点对象(%d/%d)*/
#define UGS_CHART_PGS_CHARTVCNODE _U("IMs109") /*正在检查连接节点对象(%d/%d)*/
#define UGS_CHART_PGS_CHARTVEEDGE _U("IMs110") /*正在检查空间线对象(%d/%d)*/
#define UGS_CHART_PGS_CHARTFEATUREDT _U("IMs111") /*正在检查数据集(%d/%d)*/
#define UGS_CHART_PGS_CHECKSOUNDG _U("IMs112") /*正在进行S-57水深物标对象检查...*/
#define UGS_CHART_PGS_CHARTFEATUREOBJ _U("IMs113") /*正在检查特征物标对象(%d/%d)*/
#define UGS_CHART_PGS_CHECKFEATURE _U("IMs114") /*正在进行特征物标对象检查...*/
#define UGC_CHART_PGS_CHECKFEATURERELATION _U("IMs115") /*正在进行特征物标对象关系检查...*/
#define UGS_CHART_PGS_CHARTFEATUREOBJRELATION _U("IMs116") /*正在检查特征物标对象关系(%d/%d)*/
#define UGS_CHART_PGS_CHECKSPATIALOBJECT _U("IMs117") /*正在进行空间对象检查...*/
#define UGS_CHART_PGS_CHECKSPATIALOBJECTCOALNE _U("IMs118") /*正在进行COALNE特征物标对象检查(%d/%d)*/
#define UGS_CHART_PGS_BUILDCHAINNODETOPO _U("IMs119") /*正在进行S-57连接节点拓扑关系构建*/
#define UGS_CHART_PGS_CMPTEMPDATE _U("IMs120") /*正在处理临时数据(%d/%d)*/
#define UGS_CHART_PGS_PICKCONNECTNODEFROMEDGE _U("IMs121") /*正在提取连接节点(%d/%d)*/
#define UGS_CHART_PGS_BUILDFEATURETOPO _U("IMs122") /*构建特征物标对象到空间对象的引用关系, 正在处理数据集(%d/%d)*/
#define UGS_CHART_PGS_BUILDEDGETOCONNECTNODETOPO _U("IMs123") /*构建空间线对象到连接节点的引用关系，正在处理数据(%d/%d)*/
#define UGS_CHART_PGS_CHECKOVERLAPLINE _U("IMs124") /*正在处理交叠的空间线对象(%d/%d)*/
#define UGS_CHART_PGS_BREAKLINE _U("IMs125") /*正在进行空间线段打断(%d/%d)*/
#define UGS_CHART_PGS_CHECKLINECROSSVERTEX _U("IMs126") /*正在处理相交的空间线段(%d/%d)*/
#define UGS_CHART_PGS_BUILDUSAGFIELD _U("IMs127") /*正在构建USAG字段值(%d/%d)*/
#define UGS_CHART_S58_FEATURERELATIONERROR _U("IMs128") /* 特征物标 %s %s %s*/


//嵌入式下的一些错误定义
#define LIC_UNSUPORT_MODULE _U("ErrLic01") /*许可模块不支持*/

#endif

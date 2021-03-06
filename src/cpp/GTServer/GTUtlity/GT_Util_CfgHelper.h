#ifndef GT_UTIL_CFGHELPER_H_
#define GT_UTIL_CFGHELPER_H_

#include <string>
#include <json/json.h>

namespace GT {

    namespace UTIL {

        class GT_Util_CfgHelper
        {
        public:
            GT_Util_CfgHelper();
            ~GT_Util_CfgHelper();

        public:
            static bool         LoadCfg(std::string cfgpath);
            static bool         ReadBoolCfg(std::string section, std::string key, bool defaultvalue);
            static int          ReadIntCfg(std::string section, std::string key, int defaultvalue);
            static double       ReadDoubleCfg(std::string section, std::string key, double defaultvalue);
            static std::string  ReadStringCfg(std::string section, std::string key, std::string defaultvalue);

        private:
            static std::string  cfg_content_;
			static Json::Value	cfg_root_;
			static bool			cfg_load_;
        };

    }
}

#define GT_READ_CFG_BOOL        GT::UTIL::GT_Util_CfgHelper::ReadBoolCfg
#define GT_READ_CFG_INT         GT::UTIL::GT_Util_CfgHelper::ReadIntCfg
#define GT_READ_CFG_DOUBLE      GT::UTIL::GT_Util_CfgHelper::ReadDoubleCfg
#define GT_READ_CFG_STRING      GT::UTIL::GT_Util_CfgHelper::ReadStringCfg
#endif //GT_UTIL_CFGHELPER_H_


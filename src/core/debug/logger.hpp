#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

#if defined(__GNUC__) || defined(__clang__)
    #define LOG_FUNC __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
    #define LOG_FUNC __FUNCSIG__
#else
    #define LOG_FUNC __func__
#endif

class Logger {
    public:
        enum LogLevel { Info, Warning, Error };

        static Logger& Instance() {
            static Logger l;
            return l;
        };

        inline void logger(
            LogLevel level, 
            const std::string msg,
            const char* file,
            int line,
            const char* function
        ) const {
            std::cerr << 
                getLogLevel(level) << " [" <<
                std::setw(4) << std::setfill('0') << datetime.tm_year+1900 << "/" <<
                std::setw(2) << std::setfill('0') << datetime.tm_mon+1 << "/" <<
                std::setw(2) << std::setfill('0') << datetime.tm_mday << " " <<
                std::setw(2) << std::setfill('0') << datetime.tm_hour << ":" <<
                std::setw(2) << std::setfill('0') << datetime.tm_min << ":" <<
                std::setw(2) << std::setfill('0') << datetime.tm_sec << 
                "] " << 
                file << ":" << line << " " << function << ": " << msg << std::endl;
        };

    private:
        Logger() {};
        ~Logger() {};
        Logger (Logger const&) = delete;
        Logger& operator=(Logger const&) = delete;
        time_t timestamp = time(&timestamp);
        struct tm datetime = *localtime(&timestamp);

        inline std::string getLogLevel(LogLevel level) const {
            switch (level) {
                case Info:
                    return "[I]";
                    break;
                case Warning:
                    return "[W]";
                    break;
                case Error:
                    return "[E]";
                    break;
            }
        }
};

#define log(level, msg) logger(level, msg, __FILE__, __LINE__, __func__)
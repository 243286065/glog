
#include "glog/logger.h"

int InitLogger(
    const std::string& logName,
    const std::string& logPath,
    const google::LogSeverity minSeverity,
    const unsigned int fileMaxSize)
{
    google::InitGoogleLogging(logName.c_str());
    google::SetLogDestination(google::GLOG_INFO, (logPath+logName).c_str());
    google::SetLogFilenameExtension("-");

    FLAGS_log_dir = logPath;
    FLAGS_max_log_size = fileMaxSize;
    FLAGS_stop_logging_if_full_disk = true;
    FLAGS_alsologtostderr = true;
    FLAGS_colorlogtostderr = true;
    FLAGS_logbufsecs = 0;
    FLAGS_minloglevel = minSeverity;
    FLAGS_log_link = logPath;

    google::SetStderrLogging(minSeverity);
    google::SetLogSymlink(google::GLOG_INFO, logName.c_str());

    return 0;
}


void ReleaseLogger()
{
    google::ShutdownGoogleLogging();
}

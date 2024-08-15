package main

        import (
            "errors"
            "fmt"
            "log"
            "os"
            "path"
            "runtime"
            )

    var (
        logger *log.Logger
        )

    func setupLogging(logFilePath string) {

    if len(logFilePath) > 0 {
            if logFilePath[0] != os.PathSeparator {
                    // the user has set the log file path to be a relative path so pre pend the directory

                    // get the parent directory
                logDirectory := path.Dir(logFilePath)

                      logDirectoryInfo, logDirectoryErr := os.Stat(logDirectory)

                                                if logDirectoryErr != nil || logDirectoryInfo == nil {
                        // directory doesn't exist.. so try to make it
                        os.Mkdir(logDirectory, 0700)
                    } else {
                        if !logDirectoryInfo.IsDir() {
                                panic("Log directory is a regular file")
                            }
                    }
                }

            fo, err := os.OpenFile(logFilePath, os.O_CREATE|os.O_APPEND|os.O_RDWR, 0600)

                        if err != nil {
                            panic(err)
                        }

                        logger = log.New(fo, "", log.LstdFlags)
        } else {
        panic("Missing logfile")
    }
}

func logConsole(message string, v ...interface{}) {
    logMessage := fmt.Sprintf(message, v...)
                  log.Println(logMessage)
}

func logMessage(message string, v ...interface{}) error {

    if logger == nil {
            // we have no logger so return an error
            return errors.New("Logger is nil")
        } else {

        var arg_message string

            if len(v) > 0 {
            arg_message = fmt.Sprintf(message, v...)
        } else {
            arg_message = message
        }

        _, file, line, ok := runtime.Caller(2)

                               var logMessage string

                               if ok {
            // if the filename includes the full path, then strip it
            logMessage = fmt.Sprintf("%s:%d - %s", path.Base(file), line, arg_message)
        } else {
            logMessage = arg_message
        }

        logger.Println(logMessage)

            return nil
    }
}

func logFatal(message string, v ...interface{}) {
    var arg_message string

        if len(v) > 0 {
        arg_message = fmt.Sprintf(message, v...)
    } else {
        arg_message = message
    }

    log.Fatal(arg_message)
}

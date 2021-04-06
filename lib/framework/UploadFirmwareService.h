#ifndef UploadFirmwareService_h
#define UploadFirmwareService_h

#include <Arduino.h>

#include <Update.h>
#include <WiFi.h>

#include <ESPAsyncWebServer.h>
#include <SecurityManager.h>
#include <RestartService.h>

#define UPLOAD_FIRMWARE_PATH "/rest/uploadFirmware"

class UploadFirmwareService {
  public:
    UploadFirmwareService(AsyncWebServer * server, SecurityManager * securityManager);

  private:
    SecurityManager * _securityManager;
    void              handleUpload(AsyncWebServerRequest * request, const String & filename, size_t index, uint8_t * data, size_t len, bool final);
    void              uploadComplete(AsyncWebServerRequest * request);
    void              handleError(AsyncWebServerRequest * request, int code);
    static void       handleEarlyDisconnect();
};

#endif // end UploadFirmwareService_h

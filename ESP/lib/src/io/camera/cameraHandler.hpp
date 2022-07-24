#pragma once
#include <Arduino.h>
#include <esp_camera.h>
#include "data/Observer/Observer.h"
#include "data/config/project_config.hpp"

class CameraHandler : IObserver
{
private:
    sensor_t *camera_sensor;
    camera_config_t config;
    ProjectConfig *configManager;

public:
    CameraHandler(ProjectConfig *configManager) : configManager(configManager) {}
    int setupCamera();
    int setCameraResolution(framesize_t frameSize);
    int setVFlip(int direction);
    int setHFlip(int direction);
    int setVieWindow(int offsetX, int offsetY, int outputX, int outputY);
    void update(ObserverEvent::Event event);
};

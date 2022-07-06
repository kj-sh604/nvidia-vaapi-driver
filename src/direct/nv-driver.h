#ifndef NV_DRIVER_H
#define NV_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

#include "nvidia.h"

#define ROUND_UP(N, S) ((((N) + (S) - 1) / (S)) * (S))

typedef struct {
    int nvctlFd;
    int nv0Fd;
    int drmFd;
    struct drm_nvidia_get_dev_info_params devInfo;
    uint32_t clientObject;
    uint32_t deviceObject;
    uint32_t subdeviceObject;
} NVDriverContext;

typedef struct {
    int nvFd;
    int drmFd;
    uint32_t width;
    uint32_t height;
    uint64_t mods;
    uint32_t memorySize;
    uint32_t offset;
    uint32_t pitch;
    uint32_t fourcc;
} NVDriverImage;

bool init_nvdriver(NVDriverContext *context, int drmFd);
bool get_device_uuid(NVDriverContext *context, char uuid[16]);
int alloc_memory(NVDriverContext *context, uint32_t size, uint32_t alignment, uint32_t bpc);
int alloc_image(NVDriverContext *context, uint32_t width, uint32_t height, uint8_t channels, uint8_t bytesPerChannel, NVDriverImage *image);

#endif

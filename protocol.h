#ifndef PROTOCOL_H
#define PROTOCOL_H

enum 
{
    FLUXENGINE_VERSION = 1,

    FLUXENGINE_VID = 0xF055,
    FLUXENGINE_PID = 0x9973,

    /* libusb uses these numbers */
    FLUXENGINE_DATA_OUT_EP = 0x01,
    FLUXENGINE_DATA_IN_EP = 0x82,
    FLUXENGINE_CMD_OUT_EP = 0x03,
    FLUXENGINE_CMD_IN_EP = 0x84,

    /* the PSoC code uses these, sigh */
    FLUXENGINE_DATA_OUT_EP_NUM = FLUXENGINE_DATA_OUT_EP & 0x0f,
    FLUXENGINE_DATA_IN_EP_NUM = FLUXENGINE_DATA_IN_EP & 0x0f,
    FLUXENGINE_CMD_OUT_EP_NUM = FLUXENGINE_CMD_OUT_EP & 0x0f,
    FLUXENGINE_CMD_IN_EP_NUM = FLUXENGINE_CMD_IN_EP & 0x0f,
    
    FRAME_SIZE = 64,
};

enum
{
    F_FRAME_ERROR = 0,            /* any_frame */
    F_FRAME_GET_VERSION_CMD,      /* any_frame */
    F_FRAME_GET_VERSION_REPLY,    /* version_frame */
    F_FRAME_SEEK_CMD,             /* seek_frame */
    F_FRAME_SEEK_REPLY,           /* any_frame */
    F_FRAME_MEASURE_SPEED_CMD,    /* any_frame */
    F_FRAME_MEASURE_SPEED_REPLY,  /* speed_frame */
};

enum
{
    F_ERROR_NONE = 0,
    F_ERROR_BAD_COMMAND = 1,
};

struct frame_header
{
    uint8_t type;
    uint8_t size;
};

struct any_frame
{
    struct frame_header f;
};

struct error_frame
{
    struct frame_header f;
    uint8_t error;
};

struct version_frame
{
    struct frame_header f;
    uint8_t version;
};

struct seek_frame
{
    struct frame_header f;
    uint8_t track;
};

struct speed_frame
{
    struct frame_header f;
    uint16_t period_ms;
};

#endif
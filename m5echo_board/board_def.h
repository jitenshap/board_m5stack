/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2020 <ESPRESSIF SYSTEMS (SHANGHAI) CO., LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _AUDIO_BOARD_DEFINITION_H_
#define _AUDIO_BOARD_DEFINITION_H_

/**
 * @brief SDCARD Function Definition
 */
#define FUNC_SDCARD_EN            (0)
#define SDCARD_OPEN_FILE_NUM_MAX  0
#define SDCARD_INTR_GPIO          -1


/**
 * @brief LED Function Definition
 */
#define FUNC_SYS_LEN_EN           (1)
#define WS2812_LED_GPIO_PIN       27
#define WS2812_LED_BAR_NUMBERS    1


/**
 * @brief Battery Detect Function Definition
 */
#define FUNC_BATTERY_DET_EN       (0)
#define BATTERY_DETECT_GPIO       -1


/**
 * @brief Audio Codec Chip Function Definition
 */
#ifdef M5ECHO_I2S_MODE_ADC
#define FUNC_AUDIO_CODEC_EN       (1)
#define NS4168_MCLK_GPIO          GPIO_NUM_0
#define PA_ENABLE_GPIO            -1
#define AUDIO_CODEC_DEFAULT_CONFIG(){                   \
        .adc_input  = AUDIO_HAL_ADC_INPUT_LINE1,        \
        .dac_output = AUDIO_HAL_DAC_OUTPUT_LINE1,         \
        .codec_mode = AUDIO_HAL_CODEC_MODE_LINE_IN,        \
        .i2s_iface = {                                  \
            .mode = AUDIO_HAL_MODE_MASTER,              \
            .fmt = AUDIO_HAL_I2S_NORMAL,                \
            .samples = AUDIO_HAL_16K_SAMPLES,                           \
            .bits = AUDIO_HAL_BIT_LENGTH_16BITS,        \
        },                                              \
};
#else
#define FUNC_AUDIO_CODEC_EN       (1)
#define NS4168_MCLK_GPIO          GPIO_NUM_0
#define PA_ENABLE_GPIO            -1
#define AUDIO_CODEC_DEFAULT_CONFIG(){                   \
        .adc_input  = AUDIO_HAL_ADC_INPUT_LINE1,        \
        .dac_output = AUDIO_HAL_DAC_OUTPUT_LINE1,         \
        .codec_mode = AUDIO_HAL_CODEC_MODE_DECODE,        \
        .i2s_iface = {                                  \
            .mode = AUDIO_HAL_MODE_MASTER,              \
            .fmt = AUDIO_HAL_I2S_NORMAL,                \
            .samples = AUDIO_HAL_16K_SAMPLES,                           \
            .bits = AUDIO_HAL_BIT_LENGTH_16BITS,        \
        },                                              \
};
#endif

/**
 * @brief Button Function Definition
 */
#define FUNC_BUTTON_EN            (1)
#define INPUT_KEY_NUM             1
#define BUTTON_MODE_ID            39             
#define BUTTON_PLAY_ID            -1             
#define BUTTON_VOLDN_ID           -1            
#define BUTTON_VOLUP_ID            -1            
#define BUTTON_SET_ID            -1           

#define INPUT_KEY_DEFAULT_INFO() {                      \
    {                                                   \
        .type = PERIPH_ID_BUTTON,                       \
        .user_id = INPUT_KEY_USER_ID_MODE,              \
        .act_id = BUTTON_MODE_ID,                       \
    }                                                   \
}

#endif

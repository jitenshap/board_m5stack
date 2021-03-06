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

#include "display_service.h"
#include "periph_ws2812.h"
#include "board_def.h"
#include "string.h"
#include "esp_log.h"

const struct periph_ws2812_ctrl_cfg ws2812_display_pattern[29][1] = {
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 1,
            .time_off_ms = 0,
            .time_on_ms = 0,
        }//0
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_RED,
            .loop = 1000,
            .time_off_ms = 200,
            .time_on_ms = 400,
        }//1
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_GREEN,
            .loop = 1000,
            .time_off_ms = 200,
            .time_on_ms = 400,
        }//2
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_BLUE,
            .loop = 1000,
            .time_off_ms = 200,
            .time_on_ms = 400,
        }//3
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_WHITE,
            .loop = 1000,
            .time_off_ms = 200,
            .time_on_ms = 400,
        }//4
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_CYAN,
            .loop = 1000,
            .time_off_ms = 200,
            .time_on_ms = 400,
        }//5
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_PURPLE,
            .loop = 1000,
            .time_off_ms = 200,
            .time_on_ms = 400,
        }//6
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_ORANGE,
            .loop = 1000,
            .time_off_ms = 200,
            .time_on_ms = 400,
        }//7
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_YELLOW,
            .loop = 1000,
            .time_off_ms = 200,
            .time_on_ms = 400,
        }//8
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_RED,
            .loop = 100,
            .time_off_ms = 2000,
            .time_on_ms = 2000,
        }//9
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_GREEN,
            .loop = 100,
            .time_off_ms = 2000,
            .time_on_ms = 2000,
        }//10
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_BLUE,
            .loop = 100,
            .time_off_ms = 2000,
            .time_on_ms = 2000,
        }//11
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_WHITE,
            .loop = 100,
            .time_off_ms = 2000,
            .time_on_ms = 2000,
        }//12
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_CYAN,
            .loop = 100,
            .time_off_ms = 2000,
            .time_on_ms = 2000,
        }//13
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_PURPLE,
            .loop = 100,
            .time_off_ms = 2000,
            .time_on_ms = 2000,
        }//14
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_ORANGE,
            .loop = 100,
            .time_off_ms = 2000,
            .time_on_ms = 2000,
        }//15
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_YELLOW,
            .loop = 100,
            .time_off_ms = 2000,
            .time_on_ms = 2000,
        }//16
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_RED,
            .loop = 500,
            .time_off_ms = 250,
            .time_on_ms = 250,
        }//17
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_GREEN,
            .loop = 500,
            .time_off_ms = 250,
            .time_on_ms = 250,
        }//18
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_BLUE,
            .loop = 500,
            .time_off_ms = 250,
            .time_on_ms = 250,
        }//19
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_WHITE,
            .loop = 500,
            .time_off_ms = 250,
            .time_on_ms = 250,
        }//20
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_RED,
            .loop = 1,
            .time_off_ms = 0,
            .time_on_ms = 1,
        }//21
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_GREEN,
            .loop = 1,
            .time_off_ms = 0,
            .time_on_ms = 1,
        }//22
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLUE,
            .loop = 1,
            .time_off_ms = 0,
            .time_on_ms = 1,
        }//23
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_WHITE,
            .loop = 1,
            .time_off_ms = 0,
            .time_on_ms = 1,
        }//24
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_CYAN,
            .loop = 1,
            .time_off_ms = 0,
            .time_on_ms = 1,
        }//25
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_ORANGE,
            .loop = 1,
            .time_off_ms = 0,
            .time_on_ms = 1,
        }//26
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_PURPLE,
            .loop = 1,
            .time_off_ms = 0,
            .time_on_ms = 1,
        }//27
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_YELLOW,
            .loop = 1,
            .time_off_ms = 0,
            .time_on_ms = 1,
        }//28
    }
};

int8_t get_ws2812_gpio_pin(void)
{
    return WS2812_LED_GPIO_PIN;
}

int get_ws2812_num(void)
{
    return WS2812_LED_BAR_NUMBERS;
}

void ws2812_pattern_copy(struct periph_ws2812_ctrl_cfg *p)
{
    ESP_LOGD("ws2812_pattern_copy", "has been called, %s %d", __FILE__, __LINE__);
    memcpy(p, ws2812_display_pattern, sizeof(ws2812_display_pattern));
}

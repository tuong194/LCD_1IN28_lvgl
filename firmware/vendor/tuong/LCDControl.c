//
//#include "LCDControl.h"
//#include <stdbool.h>
//#include "LCD_128.h"
//#include "image.h"
//#include "stdint.h"
//
//
///*********************
// *      DEFINES
// *********************/
//#define MY_DISP_HOR_RES    240
//#define MY_DISP_VER_RES    240
//
//
//
//static void disp_init(void);
//
//static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p);
//
//
//
//static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
//
//
//void lv_port_disp_init(void)
//{
//
//    disp_init();
//
//
//    /**
//     * LVGL requires a buffer where it internally draws the widgets.
//     * Later this buffer will passed to your display driver's `flush_cb` to copy its content to your display.
//     * The buffer has to be greater than 1 display row
//     *
//     * There are 3 buffering configurations:
//     * 1. Create ONE buffer:
//     *      LVGL will draw the display's content here and writes it to your display
//     *
//     * 2. Create TWO buffer:
//     *      LVGL will draw the display's content to a buffer and writes it your display.
//     *      You should use DMA to write the buffer's content to the display.
//     *      It will enable LVGL to draw the next part of the screen to the other buffer while
//     *      the data is being sent form the first buffer. It makes rendering and flushing parallel.
//     *
//     * 3. Double buffering
//     *      Set 2 screens sized buffers and set disp_drv.full_refresh = 1.
//     *      This way LVGL will always provide the whole rendered screen in `flush_cb`
//     *      and you only need to change the frame buffer's address.
//     */
//
//    /* Example for 1) */
//    static lv_disp_draw_buf_t draw_buf_dsc_1;
//    static lv_color_t buf_1[MY_DISP_HOR_RES * 10];                          /*A buffer for 10 rows*/
//    lv_disp_draw_buf_init(&draw_buf_dsc_1, buf_1, NULL, MY_DISP_HOR_RES * 10);   /*Initialize the display buffer*/
//
////    /* Example for 2) */
////    static lv_disp_draw_buf_t draw_buf_dsc_2;
////    static lv_color_t buf_2_1[MY_DISP_HOR_RES * 10];                        /*A buffer for 10 rows*/
////    static lv_color_t buf_2_2[MY_DISP_HOR_RES * 10];                        /*An other buffer for 10 rows*/
////    lv_disp_draw_buf_init(&draw_buf_dsc_2, buf_2_1, buf_2_2, MY_DISP_HOR_RES * 10);   /*Initialize the display buffer*/
////
////    /* Example for 3) also set disp_drv.full_refresh = 1 below*/
////    static lv_disp_draw_buf_t draw_buf_dsc_3;
////    static lv_color_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*A screen sized buffer*/
////    static lv_color_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*Another screen sized buffer*/
////    lv_disp_draw_buf_init(&draw_buf_dsc_3, buf_3_1, buf_3_2,
////                          MY_DISP_VER_RES * LV_VER_RES_MAX);   /*Initialize the display buffer*/
//
//    /*-----------------------------------
//     * Register the display in LVGL
//     *----------------------------------*/
//
//
//    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/
//
//    /*Set up the functions to access to your display*/
//
//    /*Set the resolution of the display*/
//    disp_drv.hor_res = MY_DISP_HOR_RES;
//    disp_drv.ver_res = MY_DISP_VER_RES;
//
//    /*Used to copy the buffer's content to the display*/
//    disp_drv.flush_cb = disp_flush;
//
//    /*Set a display buffer*/
//    disp_drv.draw_buf = &draw_buf_dsc_1;
//
//    /*Required for Example 3)*/
//    //disp_drv.full_refresh = 1;
//
//    /* Fill a memory array with a color if you have GPU.
//     * Note that, in lv_conf.h you can enable GPUs that has built-in support in LVGL.
//     * But if you have a different GPU you can use with this callback.*/
//    //disp_drv.gpu_fill_cb = gpu_fill;
//
//    /*Finally register the driver*/
//    lv_disp_drv_register(&disp_drv);
//}
//
///**********************
// *   STATIC FUNCTIONS
// **********************/
//
///*Initialize your display and the required peripherals.*/
//static void disp_init(void)
//{
//	LCD_RST();
//	LCD_InitReg();
//}
//
//volatile bool disp_flush_enabled = true;
//
//void disp_enable_update(void)
//{
//    disp_flush_enabled = true;
//}
//
//
//void disp_disable_update(void)
//{
//    disp_flush_enabled = false;
//}
//
//static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
//{
//
//
//	u16 i,j;
//	//u16 data[5];
//	u16 *data = (u16 *)color_p;
//	LCD_setWindow(area->x1,area->y1,area->x2,area->y2);
//	//gpio_write(DC_Pin,1);
//	for(j=area->y1;j<=area->y2;j++){
//		for(i=area->x1;i<=area->x2;i++){
//			//data[0]=color_p->full;
//			//spi_master_write(PSPI_MODULE,data,1);
//			LCD_SendData16bit(*color_p);
//			color_p++;
//			wd_clear();
//		}
//	}
//
//    lv_disp_flush_ready(disp_drv);
//}
//
//

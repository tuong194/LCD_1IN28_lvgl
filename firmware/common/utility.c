/********************************************************************************************************
 * @file     utility.c
 *
 * @brief    This is the source file for BLE SDK
 *
 * @author	 BLE GROUP
 * @date         06,2022
 *
 * @par     Copyright (c) 2022, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *******************************************************************************************************/

#include "tl_common.h"
#include "drivers.h"
#include "utility.h"


// general swap/endianess utils

void swapN(unsigned char *p, int n)
{
	int i, c;
	for (i=0; i<n/2; i++)
	{
		c = p[i];
		p[i] = p[n - 1 - i];
		p[n - 1 - i] = c;
	}
}

void swapX(const u8 *src, u8 *dst, int len)
{
    int i;
    for (i = 0; i < len; i++)
        dst[len - 1 - i] = src[i];
}

void swap16(u8 dst[2], const u8 src[2])
{
    swapX(src, dst, 2);
}


void swap24(u8 dst[3], const u8 src[3])
{
    swapX(src, dst, 3);
}

void swap32(u8 dst[4], const u8 src[4])
{
    swapX(src, dst, 4);
}

void swap48(u8 dst[6], const u8 src[6])
{
    swapX(src, dst, 6);
}

void swap56(u8 dst[7], const u8 src[7])
{
    swapX(src, dst, 7);
}

void swap64(u8 dst[8], const u8 src[8])
{
    swapX(src, dst, 8);
}

void swap128(u8 dst[16], const u8 src[16])
{
    swapX(src, dst, 16);
}



void flip_addr(u8 *dest, u8 *src){
    dest[0] = src[5];
    dest[1] = src[4];
    dest[2] = src[3];
    dest[3] = src[2];
    dest[4] = src[1];
    dest[5] = src[0];
}



void my_fifo_init (my_fifo_t *f, int s, u8 n, u8 *p)
{
	f->size = s;
	f->num = n;
	f->wptr = 0;
	f->rptr = 0;
	f->p = p;
}

u8* my_fifo_wptr (my_fifo_t *f)
{
	if (((f->wptr - f->rptr) & 255) < f->num)
	{
		return f->p + (f->wptr & (f->num-1)) * f->size;
	}
	return 0;
}

u8* my_fifo_wptr_v2 (my_fifo_t *f)
{
	if (((f->wptr - f->rptr) & 255) < f->num - 3) //keep 3 fifo left for others evt
	{
		return f->p + (f->wptr & (f->num-1)) * f->size;
	}
	return 0;
}

void my_fifo_next (my_fifo_t *f)
{
	f->wptr++;
}

int my_fifo_push (my_fifo_t *f, u8 *p, u16 n, u8 *head, u8 head_len) // BLE_SRC_TELINK_MESH_EN
{
	if (((f->wptr - f->rptr) & 255) >= f->num)
	{
		return -1;
	}

	if (n + (2+head_len) > f->size)    // sizeof(len) == 2
	{
		return -1;
	}
	u32 r = irq_disable();
	u8 *pd = f->p + (f->wptr & (f->num-1)) * f->size;
	*pd++ = (n+head_len) & 0xff;
	*pd++ = (n+head_len) >> 8;
	foreach(i,head_len){
		*pd++ = *head++;
	}
	memcpy (pd, p, n);
	f->wptr++;			// should be last for VC
	irq_restore(r);
	return 0;
}


void my_fifo_pop (my_fifo_t *f)
{
	f->rptr++;
}

u8 * my_fifo_get (my_fifo_t *f)
{
    u8 *p = 0;
    
	u32 r = irq_disable();
	if (f->rptr != f->wptr)
	{
		p = f->p + (f->rptr & (f->num-1)) * f->size;
	}
	irq_restore(r);
	
	return p;
}

u8 * my_fifo_get_offset (my_fifo_t *f, u8 offset)
{
    return (f->p + ((f->rptr + offset) & (f->num-1)) * f->size);
}

u8 my_fifo_data_cnt_get (my_fifo_t *f)
{
	return (f->wptr - f->rptr);
}

u8 my_fifo_free_cnt_get(my_fifo_t *f)
{
	return (f->num - my_fifo_data_cnt_get(f));
}

void my_fifo_reset(my_fifo_t *f)
{
	f->rptr = f->wptr;
}



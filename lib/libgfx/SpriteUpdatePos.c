#include <sprite.h>

void SpriteUpdatePos(SpriteT *spr, u_short height,
                     u_short hstart, u_short vstart)
{
  u_short vstop = vstart + height + 1;
  u_char lowctl = (hstart & 1) | (spr->ctl & 0x80);

  /*
   * SPRxPOS:
   *  Bits 15-8 contain the low 8 bits of VSTART
   *  Bits 7-0 contain the high 8 bits of HSTART
   *
   * SPRxCTL:
   *  Bits 15-8       The low eight bits of VSTOP
   *  Bit 7           (Used in attachment)
   *  Bits 6-3        Unused (make zero)
   *  Bit 2           The VSTART high bit
   *  Bit 1           The VSTOP high bit
   *  Bit 0           The HSTART low bit
   */

  if (vstart & 0x100)
    lowctl |= 4;
  if (vstop & 0x100)
    lowctl |= 2;

  {
    u_char *raw = (u_char *)spr;

    *raw++ = vstart;
    *raw++ = hstart >> 1;
    *raw++ = vstop;
    *raw++ = lowctl;
  }
}

/* Copyright 2013 the SumatraPDF project authors (see AUTHORS file).
   License: Simplified BSD (see COPYING.BSD) */

#ifndef WebpReader_h
#define WebpReader_h

#include "BaseUtil.h"

namespace webp {

bool                HasSignature(const char *data, size_t len);
Gdiplus::Size       SizeFromData(const char *data, size_t len);
Gdiplus::Bitmap *   ImageFromData(const char *data, size_t len);

}

#endif

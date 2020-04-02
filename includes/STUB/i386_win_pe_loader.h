//
// Created by silentvoid on 4/2/20.
// Copyright (c) 2020 SilentVoid. All rights reserved.
//

#ifndef SILENT_CRYPT_I386_WIN_PE_LOADER_H
#define SILENT_CRYPT_I386_WIN_PE_LOADER_H

#define I386_WIN_PE_LOADER_INFOS_SIZE 0x25
#define I386_WIN_PE_LOADER_SIZE 276

#ifndef NO_PAYLOAD
unsigned char i386_win_pe_loader_stub[] = {
        0x50, 0x57, 0x56, 0x54, 0x52, 0x51, 0xbb, 0x00, 0x00, 0x00,
        0x00, 0x81, 0xeb, 0x71, 0x00, 0x00, 0x00, 0xb8, 0x01, 0x00,
        0x00, 0x00, 0x6a, 0x10, 0x50, 0xbe, 0x21, 0x00, 0x00, 0x00,
        0x56, 0xeb, 0x10, 0x5b, 0x55, 0x6e, 0x70, 0x61, 0x63, 0x6b,
        0x69, 0x6e, 0x67, 0x2e, 0x2e, 0x2e, 0x5d, 0x0a, 0x00, 0xb8,
        0x61, 0x00, 0x00, 0x00, 0xb9, 0x69, 0x00, 0x00, 0x00, 0xba,
        0x59, 0x00, 0x00, 0x00, 0x01, 0xd8, 0x01, 0xc1, 0x30, 0x10,
        0xc1, 0xca, 0x08, 0x40, 0x39, 0xc8, 0x75, 0xf6, 0x58, 0x5f,
        0x5e, 0x5c, 0x5a, 0x59, 0xe9, 0xfb, 0xff, 0xff, 0x0f, 0xee,
        0xee, 0xee, 0xee, 0x00, 0x00, 0xaa, 0xaa, 0xaa, 0xaa, 0x00,
        0x00, 0xbb, 0xbb, 0xbb, 0xbb, 0x00, 0x00, 0x00, 0xcc, 0xcc,
        0xcc, 0xcc, 0x00, 0x00
};
#endif // NO_PAYLOAD

#endif //SILENT_CRYPT_I386_WIN_PE_LOADER_H

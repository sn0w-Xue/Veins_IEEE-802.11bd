//
// Copyright (C) 2014 Michele Segata <segata@ccs-labs.org>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#pragma once

#include <cmath>
#include <stdint.h>

#include "veins/veins.h"

namespace veins {

/** @brief Modulation and coding scheme to be used for transmission */
enum class MCS {
    // use the default MCS
    undefined = -1,
    ofdm_bpsk_r_1_2,
//    此MCS未在IEEE 802.11bd草案中取得MCS编号，去除此种MCS
//    ofdm_bpsk_r_3_4,
    ofdm_qpsk_r_1_2,
    ofdm_qpsk_r_3_4,
    ofdm_qam16_r_1_2,
    ofdm_qam16_r_3_4,
    ofdm_qam64_r_2_3,
    ofdm_qam64_r_3_4,

    // 添加三种全新MCS
    ofdm_qam64_r_5_6,
    ofdm_qam256_r_3_4,
    ofdm_qam256_r_5_6
    // 到此为止

};

/** @brief Available bandwidths */
enum class Bandwidth {
    ofdm_5_mhz,
    ofdm_10_mhz,
    ofdm_20_mhz
};

/** @brief Given bandwidth and MCS returns datarate in bits per second */
inline uint64_t getOfdmDatarate(MCS mcs, Bandwidth bw)
{
//    // divide datarate by div, depending on bandwidth
//
//    uint64_t div;
//    // datarate to be returned
//    uint64_t dr;
//    switch (bw) {
//    case Bandwidth::ofdm_5_mhz:
//        div = 4;
//        break;
//    case Bandwidth::ofdm_10_mhz:
//        div = 2;
//        break;
//    case Bandwidth::ofdm_20_mhz:
//    default:
//        div = 1;
//        break;
//    }
//    switch (mcs) {
//    case MCS::ofdm_bpsk_r_1_2:
//        dr = 6000000;
//        break;
//    case MCS::ofdm_bpsk_r_3_4:
//        dr = 9000000;
//        break;
//    case MCS::ofdm_qpsk_r_1_2:
//        dr = 12000000;
//        break;
//    case MCS::ofdm_qpsk_r_3_4:
//        dr = 18000000;
//        break;
//    case MCS::ofdm_qam16_r_1_2:
//        dr = 24000000;
//        break;
//    case MCS::ofdm_qam16_r_3_4:
//        dr = 36000000;
//        break;
//    case MCS::ofdm_qam64_r_2_3:
//        dr = 48000000;
//        break;
//    case MCS::ofdm_qam64_r_3_4:
//        dr = 54000000;
//        break;
//    default:
//        dr = 6000000;
//        break;
//    }
//    return (dr / div);
    if (bw == Bandwidth::ofdm_10_mhz) {
           if (mcs == MCS::ofdm_bpsk_r_1_2) {
               return 3300000;
           }
           if (mcs == MCS::ofdm_qpsk_r_1_2) {
               return 6500000;
           }
           if (mcs == MCS::ofdm_qpsk_r_3_4) {
               return 9800000;
           }
           if (mcs == MCS::ofdm_qam16_r_1_2) {
               return 13000000;
           }
           if (mcs == MCS::ofdm_qam16_r_3_4) {
               return 19500000;
           }
           if (mcs == MCS::ofdm_qam64_r_2_3) {
               return 26000000;
           }
           if (mcs == MCS::ofdm_qam64_r_3_4) {
               return 29300000;
           }
           if (mcs == MCS::ofdm_qam64_r_5_6) {
               return 32500000;
           }
           if (mcs == MCS::ofdm_qam256_r_3_4) {
               return 39000000;
           }
       }
       if (bw == Bandwidth::ofdm_20_mhz) {
           if (mcs == MCS::ofdm_bpsk_r_1_2) {
               return 6800000;
           }
           if (mcs == MCS::ofdm_qpsk_r_1_2) {
               return 13500000;
           }
           if (mcs == MCS::ofdm_qpsk_r_3_4) {
               return 20300000;
           }
           if (mcs == MCS::ofdm_qam16_r_1_2) {
               return 27000000;
           }
           if (mcs == MCS::ofdm_qam16_r_3_4) {
               return 40500000;
           }
           if (mcs == MCS::ofdm_qam64_r_2_3) {
               return 54000000;
           }
           if (mcs == MCS::ofdm_qam64_r_3_4) {
               return 60800000;
           }
           if (mcs == MCS::ofdm_qam64_r_5_6) {
               return 67500000;
           }
           if (mcs == MCS::ofdm_qam256_r_3_4) {
               return 81000000;
           }
           if (mcs == MCS::ofdm_qam256_r_5_6) {
               return 90000000;
           }
       }
       if (bw == Bandwidth::ofdm_5_mhz) {
           if (mcs == MCS::ofdm_bpsk_r_1_2) {
               return 1500000;
           }
           if (mcs == MCS::ofdm_qpsk_r_1_2) {
               return 3000000;
           }
           if (mcs == MCS::ofdm_qpsk_r_3_4) {
               return 4500000;
           }
           if (mcs == MCS::ofdm_qam16_r_1_2) {
               return 6000000;
           }
           if (mcs == MCS::ofdm_qam16_r_3_4) {
               return 9000000;
           }
           if (mcs == MCS::ofdm_qam64_r_2_3) {
               return 12000000;
           }
           if (mcs == MCS::ofdm_qam64_r_3_4) {
               return 13500000;
           }
       }
}

/** @brief returns the number of databits per ofdm symbol */
inline uint32_t getNDBPS(MCS mcs)
{
    uint32_t ndbps;
    switch (mcs) {
    case MCS::ofdm_bpsk_r_1_2:
        ndbps = 54;
        break;
//    case MCS::ofdm_bpsk_r_3_4:
//        ndbps = 36;
//        break;
    case MCS::ofdm_qpsk_r_1_2:
        ndbps = 108;
        break;
    case MCS::ofdm_qpsk_r_3_4:
        ndbps = 162;
        break;
    case MCS::ofdm_qam16_r_1_2:
        ndbps = 216;
        break;
    case MCS::ofdm_qam16_r_3_4:
        ndbps = 324;
        break;
    case MCS::ofdm_qam64_r_2_3:
        ndbps = 432;
        break;
    case MCS::ofdm_qam64_r_3_4:
        ndbps = 486;
        break;
    case MCS::ofdm_qam64_r_5_6:
        ndbps = 540;
        break;
    case MCS::ofdm_qam256_r_3_4:
        ndbps = 648;
        break;
    case MCS::ofdm_qam256_r_5_6:
        ndbps = 730;
        break;
    default:
        ndbps = 54;
        break;
    }
    return ndbps;
}

/** @brief returns the bandwidth in Hz */
inline uint64_t getBandwidth(Bandwidth bw)
{
    switch (bw) {
    case Bandwidth::ofdm_5_mhz:
        return 5000000;
        break;
    case Bandwidth::ofdm_10_mhz:
        return 10000000;
        break;
    case Bandwidth::ofdm_20_mhz:
        return 20000000;
        break;
    default:
        ASSERT2(false, "Invalid datarate for required bandwidth");
        return -1;
    }
}

/** @brief returns encoding given datarate */
inline MCS getMCS(uint64_t datarate, Bandwidth bw)
{
    if (bw == Bandwidth::ofdm_10_mhz) {
        if (datarate == 3300000) {
            return MCS::ofdm_bpsk_r_1_2;
        }
//        if (datarate == 4500000) {
//            return MCS::ofdm_bpsk_r_3_4;
//        }
        if (datarate == 6500000) {
            return MCS::ofdm_qpsk_r_1_2;
        }
        if (datarate == 9800000) {
            return MCS::ofdm_qpsk_r_3_4;
        }
        if (datarate == 13000000) {
            return MCS::ofdm_qam16_r_1_2;
        }
        if (datarate == 19500000) {
            return MCS::ofdm_qam16_r_3_4;
        }
        if (datarate == 26000000) {
            return MCS::ofdm_qam64_r_2_3;
        }
        if (datarate == 29300000) {
            return MCS::ofdm_qam64_r_3_4;
        }
        if (datarate == 32500000) {
            return MCS::ofdm_qam64_r_5_6;
        }
        if (datarate == 39000000) {
            return MCS::ofdm_qam256_r_3_4;
        }
    }
    if (bw == Bandwidth::ofdm_20_mhz) {
        if (datarate == 6800000) {
            return MCS::ofdm_bpsk_r_1_2;
        }
//        if (datarate == 9000000) {
//            return MCS::ofdm_bpsk_r_3_4;
//        }
        if (datarate == 13500000) {
            return MCS::ofdm_qpsk_r_1_2;
        }
        if (datarate == 20300000) {
            return MCS::ofdm_qpsk_r_3_4;
        }
        if (datarate == 27000000) {
            return MCS::ofdm_qam16_r_1_2;
        }
        if (datarate == 40500000) {
            return MCS::ofdm_qam16_r_3_4;
        }
        if (datarate == 54000000) {
            return MCS::ofdm_qam64_r_2_3;
        }
        if (datarate == 60800000) {
            return MCS::ofdm_qam64_r_3_4;
        }
        if (datarate == 67500000) {
            return MCS::ofdm_qam64_r_5_6;
        }
        if (datarate == 81000000) {
            return MCS::ofdm_qam256_r_3_4;
        }
        if (datarate == 90000000) {
            return MCS::ofdm_qam256_r_5_6;
        }
    }
    if (bw == Bandwidth::ofdm_5_mhz) {
        if (datarate == 1500000) {
            return MCS::ofdm_bpsk_r_1_2;
        }
//        if (datarate == 2250000) {
//            return MCS::ofdm_bpsk_r_3_4;
//        }
        if (datarate == 3000000) {
            return MCS::ofdm_qpsk_r_1_2;
        }
        if (datarate == 4500000) {
            return MCS::ofdm_qpsk_r_3_4;
        }
        if (datarate == 6000000) {
            return MCS::ofdm_qam16_r_1_2;
        }
        if (datarate == 9000000) {
            return MCS::ofdm_qam16_r_3_4;
        }
        if (datarate == 12000000) {
            return MCS::ofdm_qam64_r_2_3;
        }
        if (datarate == 13500000) {
            return MCS::ofdm_qam64_r_3_4;
        }
    }
    ASSERT2(false, "Invalid datarate for required bandwidth");
    return MCS::undefined;
}

} // namespace veins

//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
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

#include "veins/modules/application/traci/TraCIDemoRSU11p_test1.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"

using namespace veins;

Define_Module(veins::TraCIDemoRSU11p_test1);

void TraCIDemoRSU11p_test1::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if(!alreadyInitialize){
        alreadyInitialize = true;
//        TraCIDemo11pMessage* wsm = new TraCIDemo11pMessage();
//        wsm->setDemoData("900");
//        populateWSM(wsm);
//        sendDelayedDown(wsm,900);
        TraCIDemo11pMessage* wsm1 = new TraCIDemo11pMessage();
        wsm1->setDemoData("950");
        populateWSM(wsm1);
        sendDelayedDown( wsm1 , 950);
    }
}

void TraCIDemoRSU11p_test1::onWSA(DemoServiceAdvertisment* wsa)
{
    findHost()->getDisplayString().setTagArg("i", 1, "yellow");
}

void TraCIDemoRSU11p_test1::onBSM(DemoSafetyMessage* bsm)
{
    findHost()->getDisplayString().setTagArg("i", 1, "blue");
}

void TraCIDemoRSU11p_test1::onWSM(BaseFrame1609_4* frame)
{
    findHost()->getDisplayString().setTagArg("i", 1, "green");
}

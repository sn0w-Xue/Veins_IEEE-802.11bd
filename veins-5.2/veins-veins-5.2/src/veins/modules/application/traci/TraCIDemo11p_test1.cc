//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
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

#include "veins/modules/application/traci/TraCIDemo11p_test1.h"

#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"

using namespace veins;

Define_Module(veins::TraCIDemo11p_test1);

void TraCIDemo11p_test1::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        lastMsg_time = 0;
        lastMsg_count = 0;
        sentMessage = false;
        lastDroveAt = simTime();
        currentSubscribedServiceId = -1;
    }
}

void TraCIDemo11p_test1::onBSM(DemoSafetyMessage* bsm)
{
    findHost()->getDisplayString().setTagArg("i", 1, "red");
}

void TraCIDemo11p_test1::onWSA(DemoServiceAdvertisment* wsa)
{
    findHost()->getDisplayString().setTagArg("i", 1, "yellow");
}

void TraCIDemo11p_test1::onWSM(BaseFrame1609_4* frame)
{

    TraCIDemo11pMessage* wsm = check_and_cast<TraCIDemo11pMessage*>(frame);
    ASSERT(wsm);
    const char *thisMsg_value = wsm->getDemoData();
    int thisMsg_time = std::atoi(thisMsg_value);
    int current_time = simTime().inUnit(SIMTIME_S);
    if(lastMsg_time != thisMsg_time){
        findHost()->getDisplayString().setTagArg("i", 1, "green");
        lastMsg_time = thisMsg_time;
        lastMsg_count = 0;
        if(current_time - lastMsg_time < 10) {
            findHost()->getDisplayString().setTagArg("i", 1, "blue");
            sendDown(wsm->dup());
            scheduleAt(simTime() + 2 + uniform(0.01,0.5), wsm->dup());
            lastMsg_count++;
        }
    }

//    DemoServiceAdvertisment* wsa = new DemoServiceAdvertisment();
//    sendDown(wsa->dup());
//    scheduleAt(simTime()+2,wsa);

}

void TraCIDemo11p_test1::handleSelfMsg(cMessage* msg)
{
    TraCIDemo11pMessage* wsm = check_and_cast<TraCIDemo11pMessage*>(msg);
    sendDown(wsm->dup());

//    DemoServiceAdvertisment* wsa = check_and_cast<DemoServiceAdvertisment*>(msg);
//    sendDown(wsa->dup());


    lastMsg_count++;
    if (lastMsg_count >= 2) {
        delete (wsm);
    }else{
        scheduleAt(simTime() + 2 + uniform(0.01,0.5), wsm->dup());
    }
}

void TraCIDemo11p_test1::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);

}
;

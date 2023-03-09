/**
 * @file SpartyFactory.cpp
 * @author nick
 */

#include "SpartyFactory.h"
#include "Actor.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"


using namespace std;

/**
 * This is a factory method that creates Sparty.
 * @param imagesDir Directory that contains the images for this application
 * @return Pointer to an actor object.
 */
std::shared_ptr<Actor> SpartyFactory::Create(std::wstring imagesDir)
{

    shared_ptr<Actor> actor = make_shared<Actor>(L"Sparty");

    auto torso = make_shared<ImageDrawable>(L"Torso", imagesDir + L"/sparty_torso.png");
    torso->SetCenter(wxPoint(44, 138));
    torso->SetPosition(wxPoint(0, -114));
    actor->SetRoot(torso);

    auto lleg = make_shared<ImageDrawable>(L"Left Leg", imagesDir + L"/sparty_lleg.png");
    lleg->SetCenter(wxPoint(11, 9));
    lleg->SetPosition(wxPoint(27, 0));
    torso->AddChild(lleg);

    auto rleg = make_shared<ImageDrawable>(L"Right Leg", imagesDir + L"/sparty_rleg.png");
    rleg->SetCenter(wxPoint(39, 9));
    rleg->SetPosition(wxPoint(-2, 0));
    torso->AddChild(rleg);

    auto headb = make_shared<ImageDrawable>(L"Head Bottom", imagesDir + L"/sparty_lhead.png");
    headb->SetCenter(wxPoint(44, 31));
    headb->SetPosition(wxPoint(20, -130));
    torso->AddChild(headb);

    auto headt = make_shared<HeadTop>(L"Head Top", imagesDir + L"/sparty_head.png");
    headt->SetCenter(wxPoint(55, 109));
    headt->SetPosition(wxPoint(15, -65));
    headt->SetEyesCenter(wxPoint(54, 110));
    headt->SetInterocularDistance(30);
    headb->AddChild(headt);

    auto larm = make_shared<ImageDrawable>(L"Left Arm", imagesDir + L"/sparty_larm.png");
    larm->SetCenter(wxPoint(11,31));
    larm->SetPosition(wxPoint(80, -110));
    torso->AddChild(larm);

    auto rarm = make_shared<ImageDrawable>(L"Right Arm", imagesDir + L"/sparty_rarm.png");
    rarm->SetCenter(wxPoint(75,25));
    rarm->SetPosition(wxPoint(-50, -110));
    torso->AddChild(rarm);


    actor->AddDrawable(lleg);
    actor->AddDrawable(rleg);
    actor->AddDrawable(torso);
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);
    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);

    return actor;
}
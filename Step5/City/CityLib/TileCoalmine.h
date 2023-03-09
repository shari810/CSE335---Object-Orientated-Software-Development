/**
* @file TileCoalmine.h
*
* @author Charles B. Owen
*
* Class that implements a Coal mine tile
*/

#pragma once

#include "Tile.h"
#include "TileVisitor.h"


/**
* A Coal mine tile
*/
class TileCoalmine : public Tile
{

private :
    /// Production states
    enum class Production {
        NoProduction,
        LowProduction,
        MediumProduction,
        FullProduction
    };

    /// Current production state
    Production mProduction = Production::NoProduction;

    /// time the coalmine has been in its current state
    double mDuration = 0.00;

public:
    TileCoalmine(City *city);

    ///  Default constructor (disabled)
    TileCoalmine() = delete;

    ///  Copy constructor (disabled)
    TileCoalmine(const TileCoalmine &) = delete;

    ~TileCoalmine();

    virtual wxXmlNode* XmlSave(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    void Update(double elapsed) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    virtual void Accept(TileVisitor* visitor) override { visitor->VisitCoalmine(this); }

    /**
     * Get the production value of the coalmine
     * @return const value stored in .cpp
     */
    int GetProduction();
};


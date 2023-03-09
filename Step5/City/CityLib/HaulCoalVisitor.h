/**
 * @file HaulCoalVisitor.h
 * @author nick
 *
 *
 */

#ifndef CITY_HAULCOALVISITOR_H
#define CITY_HAULCOALVISITOR_H

#include "TileVisitor.h"
#include "TileCoalmine.h"

/**
 * Class to keep track of the coal hauled by all coalmines.
 */
class HaulCoalVisitor : public TileVisitor{

private:
    /// coal counter
    int mNumCoalHauled = 0;

public:
    /**
     * Get the number of coal produced(hauled)
     * @return Number of coal total
     */
    int GetNumCoalHauled() const { return mNumCoalHauled; }

    /**
    * Visit a TileCoalmine object
    * @param coalmine Coalmine we are visiting
    */
    void VisitCoalmine(TileCoalmine* coalmine)
    {
        mNumCoalHauled = mNumCoalHauled + coalmine->GetProduction();
    }
};

#endif //CITY_HAULCOALVISITOR_H

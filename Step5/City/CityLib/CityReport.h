/**
 * @file CityReport.h
 *
 * @author Charles B. Owen
 *
 * The city report is generated by the members of the city.
 * It is a collection of objects of type MemberReport.
 */

#pragma once

#include <unordered_map>
#include <memory>
#include <vector>
#include <list>
#include <random>

class City;
class MemberReport;

/**
 * The city report is generated by the members of the city.
 * It is a collection of objects of type MemberReport.
*/
class CityReport
{
private:
    /// The city this report is for
    City* mCity;

    /// Random number generator
    std::mt19937 mRandom;

protected:
    /// Contents of a map location for a report
    class ReportHolder {
    public:
        /// The actual report
        std::shared_ptr<MemberReport> mReport;

        /// Key for the next report or empty string if none
        std::wstring mNextReport;
    };

    /// Hash map that holds the member reports
    std::unordered_map<std::wstring, std::shared_ptr<ReportHolder>> mReports;

    /// Key for the first report in the collection
    std::wstring mFirstReportKey;

    /// Key for the last report in the collection
    std::wstring mLastReportKey;

public:
    explicit CityReport(City* city);

    void Add(std::shared_ptr<MemberReport> report);

    std::wstring RandomKey();
};

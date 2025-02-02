#ifndef _TINYXLSX_H_
#define _TINYXLSX_H_
#include <vector>
#include <string>
#include "NFComm/NFCore/NFPlatform.h"
#include "common/RapidXML/rapidxml.hpp"
#include "common/RapidXML/rapidxml_iterators.hpp"
#include "common/RapidXML/rapidxml_print.hpp"
#include "common/RapidXML/rapidxml_utils.hpp"
#include "NFComm/NFCore/NFCommon.h"

namespace MiniExcelReader
{
    struct Cell
    {
        std::string mValue;

        template<typename T>
        T value()
        {
            return NFCommon::strto<T>(mValue);
        }

        const std::string& to_string() { return mValue; }
    };

    struct Range
    {
        int firstRow;
        int lastRow;
        int firstCol;
        int lastCol;

        int rows() { return lastRow - firstRow + 1; }
        int cols() { return lastCol - firstRow + 1; }
    };

    class Sheet
    {
    public:
        ~Sheet();

        bool visible() { return _visible; }
        const std::string& getName() { return _name; }
        const std::string& title() { return _name; }
        Range& getDimension() { return _dimension; }
        int rows() { return _dimension.rows(); }
        int cols() { return _dimension.cols(); }


        Cell* getCell(int row, int col);
    private:
        friend class ExcelFile;

        int toIndex(int row, int col);

        int _sheetId;
        bool _visible;
        Range _dimension;

        std::string _rid;
        std::string _path;
        std::string _name;

        std::vector<Cell*> _cells;
    };

    class Zip;

    class ExcelFile
    {
    public:
        ~ExcelFile();
        bool open(const char* filename, bool all = true);

        Sheet* getSheet(const char* name);
        Sheet* getSheet(const std::string& name);
        std::vector<Sheet>& sheets() { return _sheets; }

    private:

        void readWorkBook(const char* filename);
        void readWorkBookRels(const char* filename);
        void readSharedStrings(const char* filename);
        void readStyles(const char* filename);
        void readSheet(Sheet& sh);

        void parseCell(const std::string& value, int& row, int& col);
        void parseRange(const std::string& value, Range& range);

        std::vector<std::string> _sharedString;
        std::vector<Sheet> _sheets;
        Zip* _zip;
    };
}


#endif

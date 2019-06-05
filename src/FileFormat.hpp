#ifndef FILE_FORMAT_HPP__
#define FILE_FORMAT_HPP__

#include <ostream>
#include <string>

// TODO DEFAULT (plain text)
// TODO CSV
// TODO XLSX
// TODO XML
// TODO HTML
// TODO TSV (tabbed separated version)
// TODO JSON
// TODO RTF

namespace file {
  enum FORMAT_SPECIFIER {
    DEFAULT, CSV, XLSX, XML, HTML, TSV, JSON, RTF
  };

  class FileFormat {
    public:
      FileFormat();
      FileFormat(FORMAT_SPECIFIER);
      ~FileFormat();

    private:
      void SetDefault();
      void SetCSV();
      void SetXLSX();
      void SetXML();
      void SetHTML();
      void SetTSV();
      void SetRTF();

      void (*file_format_writer)(std::ostream &, std::string *);
  };
};

#endif

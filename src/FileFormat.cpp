#include "FileFormat.hpp"

using namespace file;

void write_Default(std::ostream &, std::string *);
void write_CSV(std::ostream &, std::string *);
void write_XLSX(std::ostream &, std::string *);
void write_XML(std::ostream &, std::string *);
void write_HTML(std::ostream &, std::string *);
void write_TSV(std::ostream &, std::string *);
void write_JSON(std::ostream &, std::string *);
void write_RTF(std::ostream &, std::string *);

FileFormat::FileFormat() : FileFormat(DEFAULT) {

}

FileFormat::FileFormat(FORMAT_SPECIFIER specifier) {
  switch (specifier) {
    case DEFAULT:
      break;
    case CSV:
      break;
    case XLSX:
      break;
    case XML:
      break;
    case HTML:
      break;
    case TSV:
      break;
    case JSON:
      break;
    case RTF:
      break;
  }
}


void FileFormat::SetDefault() {
  file_format_writer = write_Default;
}


void FileFormat::SetCSV() {
  file_format_writer = write_CSV;
}

void FileFormat::SetXLSX() {
  file_format_writer = write_XLSX;
}


void FileFormat::SetXML() {
  file_format_writer = write_XML;
}


void FileFormat::SetHTML() {
  file_format_writer = write_HTML;
}


void FileFormat::SetTSV() {
  file_format_writer = write_TSV;
}


void FileFormat::SetRTF() {
  file_format_writer = write_RTF;
}


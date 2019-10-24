//
// Created by geo on 5/5/18.
//

#include <fstream>
#include "export.h"
#include "validator.h"

/*
 * Function which writes in a list of movies in CVS format
 * :param f_name: string -the file to write in
 * :param mv_lst: vector of movies
 * :post: throws ValidatorException if the file can't be opened
 */
void export_cvs(const std::string& f_name, const vector<Movie>& mv_lst){
    std::ofstream out(f_name, std::ios::trunc);
    if(!out.is_open()){
        throw ValidatorException({"Unable to open file: " + f_name});
    }
    for(const auto& mv : mv_lst){
        out << mv.get_title() << ",";
        out << mv.get_genre() << ",";
        out << mv.get_year() << ",";
        out << mv.get_main_actor() << std::endl;
    }
    out.close();
}

/*
 * Function which writes in a list of movies in HTML format
 * :param f_name: string -the file to write in
 * :param mv_lst: vector of movies
 * :post: throws ValidatorException if the file can't be opened
 */
void export_html(const std::string& f_name, const vector<Movie>& mv_lst){
    std::ofstream out(f_name, std::ios::trunc);

    if(!out.is_open()){
        throw ValidatorException({"Unable to open file: " + f_name});
    }
    out << "<html><body>" << std::endl;
    out << R"(<table border="1" style="width:100 % ">)" << std::endl;

    for(const auto& mv : mv_lst){
        out << "<tr>" << std::endl;
        out << "<td>" << mv.get_title() << "</td>"<<std::endl;
        out << "<td>" << mv.get_genre() << "</td>" << std::endl;
        out << "<td>" << mv.get_year() << "</td>" << std::endl;
        out << "<td>" << mv.get_main_actor() << "</td>"<<std::endl;
        out << "</tr>" << std::endl;
    }
    out.close();
}
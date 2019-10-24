"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/25/18 20:25
"""

from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *


class FilterSortMenu(QWidget):
    """
    Class for representing Filter and Sorts Menu
    """
    def __init__(self, srv, tabel):
        super(FilterSortMenu, self).__init__()
        self.__srv = srv
        self.__flt_title = QPushButton("Filtrare titlu")
        self.__flt_year = QPushButton("Filtrare an")
        self.__sort_title = QPushButton("Sortare titlu")
        self.__sort_writer = QPushButton("Sortare autor")
        self.__sort_genre = QPushButton("Sortare gen")
        self.__sort_year = QPushButton("Sortare an")
        self.__flt_text = QLineEdit()
        self.__tbl = tabel
        self.__init_menu()
        self.__init_connects()


    def __init_menu(self):
        """
        Function to initialize menu items
        :return: None
        """

        form = QWidget()
        form_lyt = QFormLayout()
        form.setLayout(form_lyt)
        form_lyt.addRow(QLabel("Text: "), self.__flt_text)
        center_lyt = QVBoxLayout()
        self.setLayout(center_lyt)
        center_lyt.addWidget(form)
        center_lyt.addWidget(self.__flt_title)
        center_lyt.addWidget(self.__flt_year)
        center_lyt.addWidget(self.__sort_title)
        center_lyt.addWidget(self.__sort_writer)
        center_lyt.addWidget(self.__sort_genre)
        center_lyt.addWidget(self.__sort_year)
        self.setWindowTitle("Meniu Filtrari-Sortari")
        self.setGeometry(50,50, 300, 300)

    def __set_table_flt(self, books):
        """
        Function which outputs a list of books into the table
        :param books: list containing Book type objects
        :return: None
        """
        all_books = self.__srv.get_all_srv()
        self.__tbl.clear()
        row = 0
        for book in all_books:

            self.__tbl.setItem(row, 0, QTableWidgetItem(str(1 + book.get_id())))
            self.__tbl.setItem(row, 1, QTableWidgetItem(book.get_title()))
            self.__tbl.setItem(row, 2, QTableWidgetItem(book.get_writer()))
            self.__tbl.setItem(row, 3, QTableWidgetItem(book.get_genre()))
            self.__tbl.setItem(row, 4, QTableWidgetItem(str(book.get_year())))
            row += 1
            if book in books:
                for j in range(0, 5):
                    self.__tbl.item(row - 1, j).setBackground(Qt.red)

    def __init_connects(self):
        """
        Function to init connects handlers
        :return: None
        """
        self.__flt_title.clicked.connect(self.__on_flt_title_click)
        self.__flt_year.clicked.connect(self.__on_flt_year_click)

    def __on_flt_title_click(self):
        """
        Function to handle flt_title click action
        :return: None
        """

        title = self.__flt_text.text()
        lst = self.__srv.filter_by_title(title)
        self.__set_table_flt(lst)

    def __on_flt_year_click(self):
        """
        Function to handle flt_year click action
        :return: None
        """

        try:
            year = int(self.__flt_text.text())
            lst = self.__srv.filter_by_year(year)
            self.__set_table_flt(lst)
        except ValueError:
            QMessageBox.warning(self, "Atentie!", "Anul trebuie sa fie un numar intreg!", QMessageBox.Ok)
"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   7/24/18 22:03
"""

from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from domain.validator import ValidatorException
from gui.filetr_sorts_menu import FilterSortMenu
from utils.helper import concatenate


class GUI(QWidget):
    """
    Class for representing our user interface
    """
    def __init__(self, srv):
        super(GUI, self).__init__()
        self.__srv = srv
        self.__tbl = QTableWidget()
        self.__id_txt = QLineEdit()
        self.__title_txt = QLineEdit()
        self.__writer_txt = QLineEdit()
        self.__genre_txt = QLineEdit()
        self.__year_txt = QLineEdit()
        self.__add_btn = QPushButton("Adauga")
        self.__del_btn = QPushButton("Sterge")
        self.__upd_btn = QPushButton("Modifica")
        self.__flt_sort_btn = QPushButton("Meniu Filtrari-Sortari")
        self.__reset_btn = QPushButton("Resetare Tabel")
        self.__undo_btn = QPushButton("Undo")
        self.__flt_sort_menu = FilterSortMenu(srv, self.__tbl)

        self.__init_gui()
        self.__populate()
        self.__set_connects()
        self.__set_table(self.__srv.get_all_srv())

    def __init_gui(self):
        """
        Function to initialize GUI components
        :return: None
        """

        self.__tbl.setColumnCount(5)
        self.__tbl.setRowCount(50)
        self.__id_txt.setEnabled(False)
        self.setWindowTitle("Biblioteca")
        form_widg = QWidget()
        frm_lyt = QFormLayout()
        form_widg.setLayout(frm_lyt)
        frm_lyt.addRow(QLabel("ID: "), self.__id_txt)
        frm_lyt.addRow(QLabel("Titlu: "), self.__title_txt)
        frm_lyt.addRow(QLabel("Autor: "), self.__writer_txt)
        frm_lyt.addRow(QLabel("Gen: "), self.__genre_txt)
        frm_lyt.addRow(QLabel("An: "), self.__year_txt)

        left_down_btns_widg = QWidget()
        left_down_lyt = QHBoxLayout()
        left_down_btns_widg.setLayout(left_down_lyt)
        left_down_lyt.addWidget(self.__flt_sort_btn)

        left_widg = QWidget()
        left_lyt = QVBoxLayout()
        left_widg.setLayout(left_lyt)
        left_lyt.addWidget(self.__tbl)
        left_lyt.addWidget(left_down_btns_widg)

        btns = QWidget()
        btns_lyt = QHBoxLayout()
        btns.setLayout(btns_lyt)
        btns_lyt.addWidget(self.__add_btn)
        btns_lyt.addWidget(self.__del_btn)
        btns_lyt.addWidget(self.__upd_btn)
        btns_lyt.addWidget(self.__reset_btn)
        btns_lyt.addWidget(self.__undo_btn)

        right_widg = QWidget()
        right_lyt = QVBoxLayout()
        right_widg.setLayout(right_lyt)
        right_lyt.addWidget(form_widg)
        right_lyt.addWidget(btns)

        center_lyt = QHBoxLayout()
        self.setLayout(center_lyt)
        center_lyt.addWidget(left_widg)
        center_lyt.addWidget(right_widg)

        self.setGeometry(50, 50, 1200, 400)

    def __set_table(self, books):
        """
        Function which outputs a list of books into the table
        :param books: list containing Book type objects
        :return: None
        """
        self.__tbl.clear()
        row = 0
        for book in books:
            self.__tbl.setItem(row, 0, QTableWidgetItem(str(1 + book.get_id())))
            self.__tbl.setItem(row, 1, QTableWidgetItem(book.get_title()))
            self.__tbl.setItem(row, 2, QTableWidgetItem(book.get_writer()))
            self.__tbl.setItem(row, 3, QTableWidgetItem(book.get_genre()))
            self.__tbl.setItem(row, 4, QTableWidgetItem(str(book.get_year())))
            row += 1

    def __populate(self):
        """
        Function which populates the service with data
        :return: None
        """
        self.__srv.add_book("Prislea", "Petre Ispirescu", "Basm", 1910)
        self.__srv.add_book("Ion", "Liviu Rebreanu", "Drama", 1912)
        self.__srv.add_book("Limite si Continuitate", "Pana Catalin", "Stiinta", 2016)
        self.__srv.add_book("Integrale", "Pana Catalin", "Stiinta", 2017)

    def __set_connects(self):
        """
        Function to set all connects
        :return: None
        """
        self.__add_btn.clicked.connect(self.__on_add_click)
        self.__tbl.clicked.connect(self.__on_select)
        self.__del_btn.clicked.connect(self.__on_del_click)
        self.__upd_btn.clicked.connect(self.__on_upd_click)
        self.__flt_sort_btn.clicked.connect(self.__on_flt_srt_click)
        self.__reset_btn.clicked.connect(self.__on_reset_btn_click)
        self.__undo_btn.clicked.connect(self.__on_undo_btn_click)

    def __on_add_click(self):
        """
        Function which adds a new book into the table
        :return: None
        """
        title = self.__title_txt.text()
        writer = self.__writer_txt.text()
        genre = self.__genre_txt.text()
        try:
            year = int(self.__year_txt.text())
            self.__srv.add_book(title, writer, genre, year)
            self.__set_table(self.__srv.get_all_srv())
        except ValidatorException as ex:
            string = concatenate(ex.get_errs())
            QMessageBox.warning(self, "Atentie", string, QMessageBox.Ok)
        except ValueError:
            QMessageBox.warning(self, "Atentie!","Campul An trebuie sa contina un numar intreg!", QMessageBox.Ok)

    def __on_select(self):
        """
        Function to display current selected book properties
        :return: None
        """

        index = self.__tbl.currentIndex()
        row = index.row()
        if row < 0:
            self.__del_btn.setText("Sterge")
            return None

        book_id = index.sibling(row, 0).data()
        title = index.sibling(row, 1).data()
        writer = index.sibling(row, 2).data()
        genre = index.sibling(row, 3).data()
        year = index.sibling(row, 4).data()

        if title is not None:
            self.__del_btn.setText("Sterge " + title)

        self.__id_txt.setText(book_id)
        self.__title_txt.setText(title)
        self.__writer_txt.setText(writer)
        self.__genre_txt.setText(genre)
        self.__year_txt.setText(year)

    def __on_del_click(self):
        """
        Function to handle delete button press
        :return: None
        """
        index = self.__tbl.currentIndex()
        row = index.row()
        if row < 0:
            return None

        book_id = int(index.sibling(row, 0).data()) - 1
        self.__del_btn.setText("Sterge")
        self.__srv.remove_book(book_id)
        self.__set_table(self.__srv.get_all_srv())

    def __on_upd_click(self):
        """
        Function to handle update button press
        :return: None
        """

        title = self.__title_txt.text()
        writer = self.__writer_txt.text()
        genre = self.__genre_txt.text()
        try:
            book_id = int(self.__id_txt.text()) - 1
            year = int(self.__year_txt.text())
            self.__srv.modify_book(book_id, title, writer, genre, year)
            self.__set_table(self.__srv.get_all_srv())
        except ValidatorException as ex:
            string = concatenate(ex.get_errs())
            QMessageBox.warning(self, "Atentie", string, QMessageBox.Ok)
        except ValueError:
            QMessageBox.warning(self, "Atentie!", "Campul An trebuie sa contina un numar intreg!", QMessageBox.Ok)
        except TypeError:
            print("ERR4")

    def __on_flt_srt_click(self):
        """
        Function to handle flt_srt_btn click
        :return: None
        """
        self.__flt_sort_menu.show()

    def __on_reset_btn_click(self):
        """
        Function to handle reset_btn click action
        :return: None
        """
        self.__set_table(self.__srv.get_all_srv())

    def __on_undo_btn_click(self):
        """
        Function to execute an undo
        :return: None
        """
        self.__srv.undo_srv()
        self.__set_table(self.__srv.get_all_srv())


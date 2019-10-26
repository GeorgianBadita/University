from domain.numar import Numar
from domain.validator import NumarValidator, ValidatorException
from utils.helper import atrib_huge, from10_q, fromq_10


def test_numar():
    numar = Numar("1291", 8)
    assert numar.get_val() == "1291"
    assert numar.get_baza() == 8
    numar.set_baza(7)
    assert numar.get_baza() == 7


def test_atrib():
    numar = Numar("1291", 8)
    huge = atrib_huge(numar)
    assert huge == [4, 1, 9, 2, 1]
    numar = Numar("010101", 2)
    huge = atrib_huge(numar)
    assert huge == [6, 1, 0, 1, 0, 1, 0]
    numar = Numar("ABCDEF", 16)
    huge = atrib_huge(numar)
    assert huge == [6, 15, 14, 13, 12, 11, 10]


def test_add():
    numar1 = Numar("1291", 10)
    numar2 = Numar("9", 10)
    sum = numar1 + numar2
    assert sum.get_val() == "1300"
    numar1 = Numar("ABC", 16)
    numar2 = Numar("1012", 16)
    sum = numar1 + numar2
    assert sum.get_val() == "1ACE"
    numar1 = Numar("0101", 2)
    numar2 = Numar("0101", 2)
    sum = numar1 + numar2
    assert sum.get_val() == "1010"
    numar1 = Numar("0101", 2)
    numar2 = Numar("0101", 3)
    try:
        sum = numar1 + numar2
        assert False
    except ValueError:
        assert True


def test_sub():
    numar1 = Numar("1291", 10)
    numar2 = Numar("9", 10)
    dif = numar1 - numar2
    assert dif.get_val() == "1282"
    numar1 = Numar("12321", 8)
    numar2 = Numar("1723", 8)
    dif = numar1 - numar2
    assert dif.get_val() == "10376"
    numar1 = Numar("0101", 2)
    numar2 = Numar("0101", 2)
    dif = numar1 - numar2
    assert dif.get_val() == "0"
    numar1 = Numar("1010", 2)
    numar2 = Numar("111", 2)
    dif = numar1 - numar2
    assert dif.get_val() == "11"
    numar1 = Numar("0101", 2)
    numar2 = Numar("0101", 3)
    try:
        dif = numar1 - numar2
        assert False
    except ValueError:
        assert True


def test_mul():
    numar1 = Numar("1291", 10)
    numar2 = Numar("91", 10)
    try:
        mul = numar2*numar1
        assert False
    except ValueError:
        assert True

    numar1 = Numar("1291", 10)
    numar2 = Numar("9", 10)
    mul = numar1*numar2
    assert mul.get_val() == "11619"
    numar1 = Numar("12321", 8)
    numar2 = Numar("7", 8)
    mul = numar1*numar2
    assert mul.get_val() == "110667"
    numar1 = Numar("12321", 8)
    numar2 = Numar("0", 8)
    mul = numar1*numar2
    assert mul.get_val() == "0"
    numar1 = Numar("ABC", 16)
    numar2 = Numar("7", 16)
    mul = numar1*numar2
    assert mul.get_val() == "4B24"


def test_div():
    numar1 = Numar("1291", 10)
    numar2 = Numar("91", 10)
    try:
        div = numar2 / numar1
        assert False
    except ValueError:
        assert True

    numar1 = Numar("1291", 10)
    numar2 = Numar("9", 10)
    div = numar1/numar2
    assert div[0].get_val() == "143"
    assert div[1].get_val() == "4"

    numar1 = Numar("ABC", 16)
    numar2 = Numar("B", 16)
    div = numar1/numar2
    assert div[0].get_val() == "F9"
    assert div[1].get_val() == "9"


def test_from_10_q():
    number = "127"
    assert from10_q(number, 16) == [7, 15]
    number = "10"
    assert from10_q(number, 2) == [1, 0, 1, 0]
    number = "125"
    assert from10_q(number, 6) == [3, 2, 5]


def test_b_10_q():
    number = Numar("127", 10)
    assert number.b_10_q(16).get_val() == "7F"
    number = Numar("10", 10)
    assert number.b_10_q(2).get_val() == "1010"
    number = Numar("125", 10)
    assert number.b_10_q(6).get_val() == "325"
    number = Numar("125", 10)
    assert number.b_10_q(4).get_val() == "1331"


def test_from_q_10():
    number = [4, 1, 3, 3, 1]
    assert fromq_10(number, 4) == [1, 2, 5]
    number = [4, 0, 1, 0, 1]
    assert fromq_10(number, 2) == [1, 0]
    number = [2, 15, 7]
    assert fromq_10(number, 16) == [1, 2, 7]


def test_b_q_10():
    number = Numar("1331", 4)
    assert number.b_q_10().get_val() == "125"
    number = Numar("1010", 2)
    assert number.b_q_10().get_val() == "10"
    number = Numar("A127", 16)
    assert number.b_q_10().get_val() == "41255"


def test_b_p_q():
    number = Numar("5274", 8)
    assert number.b_p_q(16).get_val() == "ABC"
    number = Numar("ABC", 16)
    assert number.b_p_q(8).get_val() == "5274"
    number = Numar("1111", 2)
    assert number.b_p_q(16).get_val() == "F"


def test_b_2_4():
    number = Numar("100110", 2)
    assert number.fast_2_4().get_val() == "212"
    number = Numar("1111110001", 2)
    assert number.fast_2_4().get_val() == "33301"
    number = Numar("10110", 2)
    assert number.fast_2_4().get_val() == "112"
    number = Numar("111110001", 2)
    assert number.fast_2_4().get_val() == "13301"
    number = Numar("33301", 4)
    assert number.fast_2_4().get_val() == "1111110001"
    number = Numar("13301", 4)
    assert number.fast_2_4().get_val() == "0111110001"


def test_b_2_8():
    number = Numar("1001101", 2)
    assert number.fast_2_8().get_val() == "115"
    number = Numar("111110001", 2)
    assert number.fast_2_8().get_val() == "761"
    number = Numar("115", 8)
    assert number.fast_2_8().get_val() == "001001101"
    number = Numar("761", 8)
    assert number.fast_2_8().get_val() == "111110001"


def test_b_2_16():
    number = Numar("10010101010111", 2)
    assert number.fast_2_16().get_val() == "2557"
    number = Numar("1111110010101010111", 2)
    assert number.fast_2_16().get_val() == "7E557"
    number = Numar("7E557", 16)
    assert number.fast_2_16().get_val() == "01111110010101010111"
    number = Numar("2557", 16)
    assert number.fast_2_16().get_val() == "0010010101010111"


def test_validator():
    number = Numar("", "")
    val = NumarValidator()
    try:
        val.validate(number)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errs()) == 2

    number = Numar("1284", 8)
    val = NumarValidator()
    try:
        val.validate(number)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errs()) == 1

    number = Numar("9ioo;", 10)
    try:
        val.validate(number)
        assert False
    except ValidatorException as ex:
        assert len(ex.get_errs()) == 1


test_validator()
test_b_2_16()
test_b_2_8()
test_b_2_4()
test_b_p_q()
test_b_q_10()
test_from_q_10()
test_b_10_q()
test_from_10_q()
test_div()
test_mul()
test_sub()
test_add()
test_atrib()
test_numar()


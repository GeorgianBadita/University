from hashtable import Hashtable


def test_hash():
    N = 100
    hash: Hashtable = Hashtable(N, lambda x: x % N)
    hash.add_elem(1)
    assert hash.size() == 1
    iter = hash.iterate()
    assert len(iter) == 1
    (key, value) = iter[0]
    assert key == 1
    assert value == 1

    hash.add_elem(1829)
    assert hash.size() == 2
    assert hash.search_elem(1) is True
    assert hash.search_elem(2) is False
    assert hash.delete_elem(10) is None
    assert hash.delete_elem(1829) == 1829
    assert hash.size() == 1
    hash.delete_elem(1)
    assert hash.size() == 0
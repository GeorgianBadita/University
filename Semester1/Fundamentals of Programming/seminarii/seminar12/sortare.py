"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/18/2017 08:36
"""

class Tractor:
    def __init__(self, id, nume):
        self.__id = id
        self.__nume = nume

    def get_id(self):
        return self.__id

    def get_nume(self):
        return self.__nume

    def __str__(self):
        return "id: {} nume: {}\n".format(self.get_id(), self.get_nume())

    #def __lt__(self, other):
    #    return self.__id < other.__id



l = [Tractor(1, "Darling"), Tractor(3, "Ana"), Tractor(2, "Vasile")]
print(*l)
ls = sorted(l, key=lambda tr: tr.get_nume(), reverse=True)
print(*ls)
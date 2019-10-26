"""
    @author: Badita Marin-Georgian
    @email:  geo.badita@gmail.com
    @date:   12/11/2017 20:31
"""
from Repository.medicine_repository import MedicineRepository
from UI.PharmacyUI import PharmacyUI
from UI.pharmacy_service import PharmacyService

'''
----------------------------
|Assembling the application|
----------------------------
'''
pharm_repo = MedicineRepository("medicines.txt")
pharm_serv = PharmacyService(pharm_repo)

pharm_ui = PharmacyUI(pharm_serv)

pharm_ui.show_ui()
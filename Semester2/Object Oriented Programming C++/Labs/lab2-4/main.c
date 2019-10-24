#include "repository/Repository.h"
#include "service/Service.h"
#include "utils/UserInterfaceVal.h"
#include "ui/UserInterface.h"


void testAll(){
    testCreateVector();
    testAddVector();
    testDeleteElem();
    testSearchElem();
    testModifyElem();
    testCopy();
    testGetAll();
    testTransaction();
    testCreateRepo();
    testCmps();
    testAppend();
    testSearchRepo();
    testDeleteTrans();
    testModifyTrans();
    testCreateService();
    testAddTrService();
    testDeleteTrService();
    testSearchService();
    testModifyTrService();
    testFilterByType();
    testFilterbySum();
    testSortDay();
    testSortSum();
    testValidateInteger();
    testGetInteger();
    testValidateSum();
    testValidateDay();
    testValidateType();
    testCreateUndo();
    testAddRepo();
    testPopServ();

}

int main() {
    testAll();
    TransRepo* repo = createRepository(10);
    Undo* undoL = createUndo();
    Service* srv = createService(repo, undoL);
    UI* userInterface = createUI(srv);
    showUI(userInterface);
    destroyUI(userInterface);
    return 0;
}
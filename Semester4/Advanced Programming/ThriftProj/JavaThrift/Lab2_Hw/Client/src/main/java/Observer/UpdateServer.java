package Observer;


import ctrls.MainController;

public class UpdateServer implements UpdateService.Iface {

    MainController mainController = null;
    
    public UpdateServer(){
    }

    public void setController(MainController controller){
        this.mainController = controller;
    }


    @Override
    public void update() {
        try {
            //System.out.println("Received update signal.");
            System.out.println("main controller update block set to " + mainController.updateBlock);
            if (mainController != null && !mainController.updateBlock) {
                System.out.println("Received update signal.");
                //Thread.sleep(50);
                this.mainController.handleRefresh();
                System.out.println("=========================handle refresh");
            }
        }
        catch (Exception e){
            e.printStackTrace();
        }
        System.out.println("Exiting update method");

    }
}

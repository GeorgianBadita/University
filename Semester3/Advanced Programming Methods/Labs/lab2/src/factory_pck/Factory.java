package factory_pck;

import container_pck.Container;

public interface Factory {

    Container createContainer(Strategy s);
}

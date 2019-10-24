package objProtocol;

import java.io.Serializable;

public interface IRequest extends Serializable {

    Object getData();
    RequestType getRequestType();
}

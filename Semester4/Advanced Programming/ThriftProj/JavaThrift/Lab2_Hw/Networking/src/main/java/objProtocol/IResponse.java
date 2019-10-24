package objProtocol;

import java.io.Serializable;

public interface IResponse extends Serializable {
    Object getData();
    ResponseType getResponseType();

}

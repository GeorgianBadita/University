package objProtocol;

import java.io.Serializable;

public class SimpleRequest implements IRequest, Serializable {

    private Object data;
    private RequestType requestType;

    public SimpleRequest(RequestType requestType){
        this.requestType = requestType;
        this.data = null;
    }

    @Override
    public String toString() {
        return "SimpleRequest{" +
                "data=" + data +
                ", requestType=" + requestType +
                '}';
    }

    public SimpleRequest(RequestType requestType, Object data){
        this.requestType = requestType;
        this.data = data;
    }

    @Override
    public Object getData() {
        return data;
    }

    @Override
    public RequestType getRequestType() {
        return this.requestType;
    }
}

package objProtocol;

import java.io.Serializable;

public class SimpleResponse implements IResponse, Serializable {
    private Object data;
    private ResponseType responseType;

    public SimpleResponse(ResponseType responseType){
        this.responseType = responseType;
        this.data = null;
    }

    @Override
    public String toString() {
        return "SimpleResponse{" +
                "data=" + data +
                ", responseType=" + responseType +
                '}';
    }

    public SimpleResponse(ResponseType responseType, Object data){
        this.data = data;
        this.responseType = responseType;
    }

    @Override
    public Object getData() {
        return this.data;
    }

    @Override
    public ResponseType getResponseType() {
        return this.responseType;
    }
}

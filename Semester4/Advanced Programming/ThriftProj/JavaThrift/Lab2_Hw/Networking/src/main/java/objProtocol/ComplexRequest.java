package objProtocol;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ComplexRequest implements IRequest, Serializable {

    private List<Object> data;
    private RequestType requestType;

    public ComplexRequest(RequestType requestType){
        this.data = null;
        this.requestType = requestType;
    }

    public ComplexRequest(RequestType requestType, Object[] data){
        this.data = new ArrayList<Object>(Arrays.asList(data));
        this.requestType = requestType;
    }

    @Override
    public String toString() {
        return "ComplexRequest{" +
                "data=" + data +
                ", requestType=" + requestType +
                '}';
    }

    @Override
    public Object getData() {
        return this.data;
    }

    @Override
    public RequestType getRequestType() {
        return requestType;
    }
}

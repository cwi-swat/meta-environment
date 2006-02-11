package casestudy.iiop;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface AddressBook extends Remote {
  public void setAddress(String name, String address) throws RemoteException;
  public String getAddress(String name) throws RemoteException;
}

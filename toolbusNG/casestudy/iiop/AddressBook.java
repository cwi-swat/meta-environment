package casestudy.iiop;

import java.rmi.*;

public interface AddressBook extends Remote {
  public void setAddress(String name, String address) throws RemoteException;
  public String getAddress(String name) throws RemoteException;
}

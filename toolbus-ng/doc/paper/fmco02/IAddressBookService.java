import java.rmi.*;

public interface IAddressBookService extends Remote {
  public int createEntry() throws RemoteException;
  public void deleteEntry(int id) throws RemoteException;
  public void setName(int id, String name) throws RemoteException;
  public void setAddress(int id, String address) throws RemoteException;
  public int findByName(String name) throws RemoteException;
}

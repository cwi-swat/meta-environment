import java.util.*
public class AddressBookService implements AddressBookTif
{
  private Map addressMap;

  public AddressBookService() { addressMap = new HashMap(); }

  private Address find(String id) { return (Address) addressMap.get(id); }

  public void deleteAddress(String id) { addressMap.remove(id); }
  public void setNumber(String id, int number) { find(id).setNumber(number); }
  public void setStreet(String id, String street) { find(id).setStreet(street); }
  public void setZip(String id, String zip) { find(id).setZip(number); }
  public ATerm createAddress() {
    Address address = new Address();
    addressMap.put(address.getId(), address);
    return address.getId();
  }
  public void recTerminate(ATerm t0);
}

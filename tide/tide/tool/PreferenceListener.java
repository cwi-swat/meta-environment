package tide.tool;

public interface PreferenceListener
{
  public void preferencesChanged(PreferenceSet set);
  public void preferenceChanged(PreferenceSet set, String name,
				String oldValue, String newValue);
  public void preferencesStatusChanged(PreferenceSet set, boolean clean);
}

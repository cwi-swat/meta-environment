require File.dirname(__FILE__) + '/../test_helper'

class SiRevisionTest < Test::Unit::TestCase
  fixtures :si_revisions

  def setup
    @si_revision = SiRevision.find(1)
  end

  # Replace this with your real tests.
  def test_truth
    assert_kind_of SiRevision,  @si_revision
  end
end

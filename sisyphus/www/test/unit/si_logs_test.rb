require File.dirname(__FILE__) + '/../test_helper'

class SiLogsTest < Test::Unit::TestCase
  fixtures :si_logs

  def setup
    @si_logs = SiLogs.find(1)
  end

  # Replace this with your real tests.
  def test_truth
    assert_kind_of SiLogs,  @si_logs
  end
end

proc tide-exec-control { dap pids mode } {
    tide-create-rule ec $dap $pids {always at} "" $mode one-shot
}

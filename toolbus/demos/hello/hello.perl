sub get_text {
   do TBsend("snd-value(\"Hello World, my first ToolBus tool in Perl!\n\")");
}

sub rec_terminate {
    local($n) = @_;

    exit(0);
}

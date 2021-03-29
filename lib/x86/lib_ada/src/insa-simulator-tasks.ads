-- Package Insa.Simulator.Tasks
-- Functions for doing background task with simulator
--

-- pragma Ada_95;

with Insa.Timer;

package Insa.Simulator.Tasks is
   
   SocketTaskException           : exception;
   
   -----------------------------------------------------------------------------
   -- SocketListener task related function and procedure
   -----------------------------------------------------------------------------
   procedure StartSocketListenerTask;
   procedure StopSocketListenerTask;
   
   -----------------------------------------------------------------------------
   -- Timer task related function and procedure
   -----------------------------------------------------------------------------
   procedure StartTimerTask;
   procedure StopTimerTask;
   procedure SetTimerCallback (Callback: TIMER.TIMER_CALLBACK);
   
end Insa.Simulator.Tasks;

###########################################################
# No user customization below this line
###########################################################

import GPS


def on_gps_started(hook_name):
    templates_addon_dir = GPS.File("/mnt/commetud/2eme Annee IMACS/ADA/TP_templates")
    GPS.ProjectTemplate.add_templates_dir(templates_addon_dir)
    GPS.Console("Messages").write(templates_addon_dir.name()+" added\n")

def init():
    GPS.Console("Messages").write("Load: TPs templates directory\n")
    GPS.Hook("gps_started").add(on_gps_started)

init()

UTILSDIR=./utils/
SERVERDIR=./server_src/
CLIENTDIR=./client_src/

help:
	@echo "Targets: "
	@echo " all_shared  - clean and make all src directories with a shared lib"
	@echo " all_static  - clean and make all src directories with a static lib"
	@echo " clean       - remove all executables, libraries, and objects"

all_shared:
	@$(MAKE) -C $(UTILSDIR) shared
	@$(MAKE) -C $(SERVERDIR) clean all
	@$(MAKE) -C $(CLIENTDIR) clean all

all_static:
	@$(MAKE) -C $(UTILSDIR) static
	@$(MAKE) -C $(SERVERDIR) clean all
	@$(MAKE) -C $(CLIENTDIR) clean all

clean:
	@$(MAKE) -C $(UTILSDIR) $@
	@$(MAKE) -C $(SERVERDIR) $@
	@$(MAKE) -C $(CLIENTDIR) $@

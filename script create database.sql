CREATE TABLE marque(
	id_marque INT primary key NOT NULL AUTO_INCREMENT, 
    nom_marque VARCHAR(30) NOT NULL
);

CREATE TABLE model_marque(
	id_model_marque int primary key not null auto_increment,
    fk_marque int not null, 
    pr_model varchar(256) not null,
    foreign key (fk_marque) references marque(id_marque)
);

CREATE TABLE produit
(
	pr_cd_pr bigint(16) primary key not null auto_increment,
    pr_codebarre bigint(14) default null , 
    pr_refour varchar(40) not null, 
    pr_desi varchar(100) not null,
    pr_prac decimal(8,2) not null,
    pr_prix decimal(8,2) not null default 0,
    pr_pack int(11) not null,
    fk_model_marque int not null,
    foreign key (fk_model_marque) references model_marque(id_model_marque)
);
